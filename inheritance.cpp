#include<bits/stdc++.h>
using namespace std;

class SocialWebsite {
        public :
        virtual void secret(){};
	protected:
	private:
};

class Facebook : public SocialWebsite{
	private: 
	   string fbPassword;
	  void secret(){
	    cout << "password" << fbPassword << endl;
	    cout << "its risky" << endl;
	  }
	public : 
	  Facebook(string pwd){
            fbPassword = pwd;
	  }
};



int main(){

   Facebook f("chetan@123");
   SocialWebsite * pt = &f;
   pt->secret();

}
