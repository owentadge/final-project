#include<iomanip>
#include"Catalogue.h"



int main()
{
  // Instantiate catalogue container and fill with one particle and one antiparticle of each type
  Catalogue testCatalogue;
  // This also covers the input checking aspect - many of these are non-physical four-momenta
  testCatalogue.add<Up>(Up(100, 20, 31, 2, false, RED));
  testCatalogue.add<Down>(Down(310, 22, 4, 3, false, BLUE));
  testCatalogue.add<Strange>(Strange(122, 3, 4, 5, true, ANTIGREEN));
  testCatalogue.add<Charm>(Charm(234, 34, 6, 0.2, false, GREEN));
  testCatalogue.add<Top>(Top(23442124.3, 12, 5, 99.24432, true, ANTIRED));
  testCatalogue.add<Bottom>(Bottom(34234.122, 45, 199.1, 4, true, ANTIBLUE));
  testCatalogue.add<Electron>(Electron(100, 3, 4, 6, false, {50, 25, 10, 15}));
  testCatalogue.add<Muon>(Muon(340.11, 342, 1, 7.123456789, true, true));
  testCatalogue.add<Tau>(Tau(199.2, 32, 20, 4.5, false, TauDecayType::UD));
  testCatalogue.add<ElectronNeutrino>(ElectronNeutrino(100, 1, 2, 3, false, false));
  testCatalogue.add<MuonNeutrino>(MuonNeutrino(4456.23, 33.3, 12.68, 12, true, false));
  testCatalogue.add<TauNeutrino>(TauNeutrino(232345.446, 25624.2, 34, 111.1, false, true));
  testCatalogue.add<Gluon>(Gluon(10023.44, 12, 12, 33.222, std::make_pair<ColourCharge, ColourCharge>(RED, ANTIGREEN)));
  testCatalogue.add<Photon>(Photon(199, 12, 1, 12));
  testCatalogue.add<WBoson>(WBoson(3569, 34, 33, 2, false, WDecayType::TAU));
  testCatalogue.add<ZBoson>(ZBoson(94936, 32, 222.22, 11.1234, ZDecayType::ELECTRONNEUTRINO));
  testCatalogue.add<Higgs>(Higgs(75438, 234, 3, 55, HiggsDecayType::PHOTON));
  testCatalogue.add<Up>(Up(100, 20, 31, 2, true, ANTIRED));
  testCatalogue.add<Down>(Down(310, 22, 4, 3, true, ANTIBLUE));
  testCatalogue.add<Strange>(Strange(122, 3, 4, 5, false, GREEN));
  testCatalogue.add<Charm>(Charm(234, 34, 6, 0.2, true, ANTIGREEN));
  testCatalogue.add<Top>(Top(23442124.3, 12, 5, 99.24432, false, RED));
  testCatalogue.add<Bottom>(Bottom(34234.122, 45, 199.1, 4, false, BLUE));
  testCatalogue.add<Electron>(Electron(100, 3, 4, 6, true, {50, 25, 10, 15}));
  testCatalogue.add<Muon>(Muon(340.11, 342, 1, 7.123456789, false, false));
  testCatalogue.add<Tau>(Tau(199.2, 32, 20, 4.5, false, TauDecayType::ELECTRON));
  testCatalogue.add<ElectronNeutrino>(ElectronNeutrino(100, 1, 2, 3, false, false));
  testCatalogue.add<MuonNeutrino>(MuonNeutrino(4456.23, 33.3, 12.68, 12, true, false));
  testCatalogue.add<TauNeutrino>(TauNeutrino(232345.446, 25624.2, 34, 111.1, false, true));
  testCatalogue.add<Gluon>(Gluon(10023.44, 12, 12, 33.222, std::make_pair<ColourCharge, ColourCharge>(RED, ANTIGREEN)));
  testCatalogue.add<Photon>(Photon(199, 12, 1, 12));
  testCatalogue.add<WBoson>(WBoson(3569, 34, 33, 2, true, WDecayType::TAU));
  testCatalogue.add<ZBoson>(ZBoson(94936, 32, 222.22, 11.1234, ZDecayType::ELECTRONNEUTRINO));
  testCatalogue.add<Higgs>(Higgs(75438, 234, 3, 55, HiggsDecayType::PHOTON));  
  // Print data for the whole catalogue
  testCatalogue.print_all();

  // Print catalogue size
  std::cout<<"Total number of particles: "<<testCatalogue.size()<<endl<<endl;

  std::cout<<"The following warnings are from proving input checking works:"<<endl;
  // Try and make some particles with bad charcteristics to show input checking
  // Gluons must have one anti and one non-anti colour charge
  Gluon wrongGluon = Gluon(100.8, 1.2, 2.2, 4, std::make_pair<ColourCharge, ColourCharge>(RED, RED));
  // Anti-quarks need anti colour charge
  Up wrongUp = Up(132, 34, 5, 1.23, true, RED);
  std::cout<<"A gluon was instantiated with red-red colour charges. The following particle was created, showing the right correction:"<<endl;
  wrongGluon.print_data();
  std::cout<<"An up antiquark was instantiated with red colour charge. The following particle was created, showing the right correction:"<<endl;
  wrongUp.print_data();

  system("pause");
  return 0;
}