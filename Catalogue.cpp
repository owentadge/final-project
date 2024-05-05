#include"Catalogue.h"

// Constructors
// Copy
Catalogue::Catalogue(Catalogue& catalogue_in) {particle_set = catalogue_in.particle_set;}
// Move
Catalogue::Catalogue(Catalogue&& catalogue_in) {particle_set = move(catalogue_in.particle_set);}

// Operator overloads
// Copy assignment
Catalogue& Catalogue::operator=(Catalogue& catalogue_in)
{
  if(&catalogue_in == this){return *this;}
  else
  {
    particle_set = catalogue_in.particle_set;
    return *this;
  }
}
// Move assignment
Catalogue& Catalogue::operator=(Catalogue&& catalogue_in)
{
  if(&catalogue_in == this){return *this;}
  else
  {
    particle_set = move(catalogue_in.particle_set);
    return *this;
  }
}
// Addition
Catalogue Catalogue::operator+(Catalogue& catalogue_in)
{
  Catalogue temp;
  for(ums::iterator i = catalogue_in.particle_set.begin(); i != catalogue_in.particle_set.end(); i++){temp.particle_set.insert(*i);}
  for(ums::iterator i = particle_set.begin(); i != particle_set.end(); i++){temp.particle_set.insert(*i);}
  return temp;
}

// Get size
int Catalogue::size() {return particle_set.size();}

// Get total four-momentum of catalogue
FourMomentum Catalogue::total_four_momentum()
{
  FourMomentum total{0,0,0,0};
  for(ums::iterator i = particle_set.begin(); i != particle_set.end(); i++)
  {
    total = total + (*i)->get_four_momentum();
  }
  return total;
}

// Printer
void Catalogue::print_all()
{
  std::cout<<"Catalogue members:"<<endl;
  for(ums::iterator i = particle_set.begin(); i != particle_set.end(); i++)
  {
    (*i)->print_data();
    std::cout<<">>~~~~~~~~~~~~~~~~~~~~~~~~~~<<"<<endl<<endl;
  }
  std::cout<<">>----END OF CATALOGUE----<<"<<endl<<endl<<endl;
}