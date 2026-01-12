#include<iostream>
#include<cstring>
using namespace std;
class Category{
	private:
		char name[20];
	public:
		Category(){
			strncpy(name,"unamed",20);
		}
		Category(char* name){
			strncpy(this->name,name,20);
		}
		~Category(){
		}
		void print(){
			cout<<"Category: "<<name<<endl;
		}
		
};
class NewsArticle{
	private:
		Category category;
		char title[30];
	public:
		NewsArticle(){
			strncpy(title,"untitled",30);
		}
		NewsArticle(Category category, char*title="untitled"){
			this->category=category;
			strncpy(this->title,title,30);
		}
		~NewsArticle(){
		}
		void print(){
			cout<<"Article title: "<<title<<endl;
			category.print();
		}
};
class FrontPage{
	private:
		NewsArticle article;
		float price;
		int editionnumber;
	public:
		FrontPage(){
			price=0.0;
			editionnumber=0;
		}
		FrontPage(NewsArticle article, float price=0.0, int editionnumber=0){
			this->article=article;
			this->price=price;
			this->editionnumber=editionnumber;
		}
		~FrontPage(){
		}
		void print(){
			cout<<"Price: "<<price<<", "<<"Edition number: "<<editionnumber<<endl;
			article.print();
		}
		
};
int main(){
	char categoryname[20];
	char articletitle[30];
	float price;
	int editionnumber;
	
	int testcase;
	cin>>testcase;
	
	if (testcase==1){
		int iter;
		cin>>iter;
		while(iter>0){
			cin>>categoryname;
			cin>>articletitle;
			cin>>price;
			cin>>editionnumber;
			Category category(categoryname);
			NewsArticle article(category,articletitle);
			FrontPage frontpage(article,price,editionnumber);
			frontpage.print();
			iter--;
		}
	}
	else if (testcase==2){
			cin>>categoryname;
			cin>>price;
			cin>>editionnumber;
			Category category(categoryname);
			NewsArticle article(category);
			FrontPage frontpage(article,price,editionnumber);
			frontpage.print();
	}
	else if(testcase==3){
			cin>>categoryname;
			cin>>articletitle;
			cin>>price;
			Category category(categoryname);
			NewsArticle article(category,articletitle);
			FrontPage frontpage(article,price);
			frontpage.print();
	}
	else{
		FrontPage frontpage=FrontPage();
		frontpage.print();
	}
	return 0;
}












