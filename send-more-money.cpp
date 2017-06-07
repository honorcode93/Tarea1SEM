#include <gecode/int.hh>
#include <gecode/minimodel.hh>
#include <gecode/search.hh>

//Para no escribir gecode!
using namespace Gecode;

//Clase send money
class SendMoreMoney : public Space {
protected:
  IntVarArray l; //Un arreglo de variables enteras (una para cada letra)
public:
  SendMoreMoney(void) : l(*this, 8, 0, 9) {

    //Inicializar cada variable en 0
    IntVar s(l[0]), e(l[1]), n(l[2]), d(l[3]),
           m(l[4]), o(l[5]), r(l[6]), y(l[7]);
    rel(*this, s != 0);
    rel(*this, m != 0);
    distinct(*this, l);
    rel(*this,             1000*s + 100*e + 10*n + d
                         + 1000*m + 100*o + 10*r + e
              == 10000*m + 1000*o + 100*n + 10*e + y);

    
    branch(*this, l, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
  }


  SendMoreMoney(bool share, SendMoreMoney& s) : Space(share, s) {
    l.update(*this, share, s.l);
  }


  virtual Space* copy(bool share) {
    return new SendMoreMoney(share,*this);
  }


  void print(void) const {
    std::cout << l << std::endl;
  }
};

int main(int argc, char* argv[]) {
  SendMoreMoney* m = new SendMoreMoney;
  DFS<SendMoreMoney> e(m); //DFS -> 
  delete m;
  while (SendMoreMoney* s = e.next()) {
    s->print(); delete s;
  }
}
