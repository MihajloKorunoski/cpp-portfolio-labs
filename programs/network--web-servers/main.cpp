#include<iostream>
#include<cstring>
using namespace std;
class Webserver;

class Webpage{
	private:
		char url[100];
		char *sodrzhina;
	public:
		Webpage(char* url="", char* sodrzhina=""){
			strcpy(this->url,url);
			this->sodrzhina=new char[strlen(sodrzhina)+1];
			strcpy(this->sodrzhina, sodrzhina);
		}
		Webpage(const Webpage &wp){
			strcpy(this->url, wp.url);
			this->sodrzhina=new char [strlen (wp.sodrzhina)+1];
			strcpy(this->sodrzhina,wp.sodrzhina);
		}
		~Webpage(){
			delete [] sodrzhina;
		}
		bool daliseisti(Webpage& wp){
			return strcmp(url,wp.url)==0;
		}
		Webpage& operator=(Webpage &wp){
			if(this != &wp){
				strcpy(this->url, wp.url);
				delete[] sodrzhina;
				this->sodrzhina=new char[strlen(wp.sodrzhina)+1];
				strcpy(this->sodrzhina,wp.sodrzhina);
			}
			return *this;
		}
		friend class Webserver;
};
class Webserver{
	private:
		char ime[30];
		int count;
		Webpage* wp;
	public:
		Webserver(const char *ime="",int count=0, Webpage *wp=0){
			strcpy(this->ime,ime);
			this->count=count;
			this->wp=new Webpage[count];
			for(int i=0;i<count;i++){
				this->wp[i]=wp[i];
			}
		}
		Webserver(const Webserver &ws){
			strcpy(this->ime,ws.ime);
			this->count=ws.count;
			this->wp=new Webpage[count];
			for(int i=0; i<count;i++){
				this->wp[i]=ws.wp[i];
			}
		}
		Webserver &operator =(const Webserver &ws){
			if(this!=&ws){
				strcpy(this->ime,ws.ime);
				this->count=ws.count;
				delete [] this-> wp;
				this->wp=new Webpage[count];
				for(int i=0;i<count; i++){
					this->wp[i]=ws.wp[i];
				}
			}
			return *this;
		}
		~Webserver(){
			delete [] wp;
		}
		Webserver& addpage(Webpage webpage){
			Webpage * tmp = new Webpage[count +1];
			for(int i=0;i<count;i++){
				tmp[i]=wp[i];
			}
			tmp[count++]=webpage;
			delete[] wp;
			wp=tmp;
			return *this;
		}
		Webserver& deletepage(Webpage webpage){
			int newcount=0;
			for(int i=0;i<count;i++){
				if(!wp[i].daliseisti(webpage))
				newcount++;
			}
			Webpage* tmp= new Webpage[newcount];
			newcount=0;
			for(int i=0;i<count;i++){
				if(!wp[i].daliseisti(webpage)){
					tmp[newcount++]=wp[i];
				}
			}
			delete[] wp;
			wp=tmp;
			count=newcount;
			return *this;
		}
		void listpages(){
			cout<<"Number: "<<count<<endl;
			for(int i=0; i<count;i++){
				cout<<wp[i].sodrzhina<<"- "<<wp[i].url<<endl;
			}
		}
};
int main () {
  Webpage wp1 ("http://www.google.com", "The search engine");
  Webpage wp2 ("http://www.finki.ukim.mk", "FINKI");
  Webpage wp3 ("http://www.time.mk", "Site vesti");
  Webserver ws(" Server ");
  ws.addpage(wp1) ;
  ws.addpage(wp2);
  ws.addpage(wp3) ;
  ws.listpages ();
  cout << "\nAfter delete: \n";
  ws.deletepage(wp3);
  ws.listpages ();
  return 0;
}
























