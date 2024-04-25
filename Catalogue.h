#ifndef Catalogue_h
#define Catalogue_h
#include<unordered_set>
#include<typeinfo>
#include"Higgs.h"
#include"Gluon.h"

typedef std::unordered_multiset<shared_ptr<Particle>> ums;

class Catalogue
{
protected:
  ums particle_set;
public:
  // Constructors
  // Default
  Catalogue() = default;
  // Copy
  Catalogue(Catalogue& catalogue_in);
  // Move
  Catalogue(Catalogue&& catalogue_in);

  // Destructor
  ~Catalogue(){}

  // Operator overloads
  // Copy assignment
  Catalogue& operator=(Catalogue& catalogue_in);
  // Move assignment
  Catalogue& operator=(Catalogue&& catalogue_in);
  // Addition
  Catalogue operator+(Catalogue& catalogue_in);

  // Add particle to catalogue
  template<class c_type> void add(c_type particle_in);

  // Getters
  // Returns total number of particles
  int size();
  // Return number of particles of same type as input
  template<class c_type> int get_amount_like();
  // Return catalogue of all particles of same type as input
  template<class c_type> Catalogue get_all_like();
  // Return total four-momentum of all particles
  FourMomentum total_four_momentum();

  // Printers
  // Print data for all particles
  void print_all();
};


// Add particle to catalogue
template<class c_type> void Catalogue::add(c_type particle_in) {particle_set.insert(std::make_shared<c_type>(particle_in));}

// Get number of similar particles
template<class c_type> int Catalogue::get_amount_like()
{
  int count{};
  for(ums::iterator i = particle_set.begin(); i != particle_set.end(); i++)
  {
    if(typeid(*(*i)) == typeid(c_type)) count++;
  }
  return count;
}

#endif