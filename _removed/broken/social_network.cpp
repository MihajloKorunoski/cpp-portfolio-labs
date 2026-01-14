#include <iostream>
#include <cstring>
using namespace std;
class InvalidPassword{
public:
char text[30];
InvalidPassword(char * t){
    strcpy(text, t);
}
void print(){
    cout << text << endl;
}
};
 
class InvalidEmail{
public:
char text[30];
InvalidEmail(char * t){
    strcpy(text, t);
}
 
void print(){
    cout << text << endl;
}
};
 
class MaximumSizeLimit{
public:
int n;
MaximumSizeLimit(int n){
    this->n=n;
}
void print(){
    cout << "You can't add more than "<< n << " users." << endl;
}
};
 
class User{
    char username[50];
    char password[50];
    char email[50];
 
public:
    User(const char * u = "", const char * p = "", const char * e = ""){
        int lower = 0, upper = 0, numbers = 0, special = 0;
 
        for (int i = 0; i < strlen(p); i++){
            if (islower(p[i]))
            lower++;
 
            if (isupper(p[i]))
            upper++;
 
            if (isdigit(p[i]))
            numbers++;
        }
 
        for (int i = 0; i < strlen(e); i++){
            if (e[i] == '@')
            special++;
        }
 
 
        if (lower == 0 || upper == 0 || numbers == 0)
        throw InvalidPassword("Password is too weak."); //1 = bad password
 
        if (special != 1)
        throw InvalidEmail("Mail is not valid.");
 
        strcpy(username, u);
        strcpy(password, p);
        strcpy(email, e);
    }
 
    virtual double popularity() = 0;
};
 
class FacebookUser : public User{
    int friends, likes, comments;
 
public:
    FacebookUser(const char * u = "", const char * p = "", const char * e = "", int friends = 0, int likes = 0, int comments = 0)
    :User(u,p,e){
        this -> friends = friends;
        this -> likes = likes;
        this -> comments = comments;
    }
 
    double popularity(){
        return (likes * 0.1) + (comments * 0.5) + friends;
    }
};
 
class TwitterUser : public User{
    int followers, tweets;
 
public:
    TwitterUser(const char * u = "", const char * p = "", const char * e = "", int followers = 0, int tweets = 0):User(u,p,e){
        this->followers = followers;
        this->tweets = tweets;
    }
 
    double popularity(){
        return tweets * 0.5 + followers;
    }
};
 
class SocialNetwork{
    User ** niza;
    int n;
    static int max;
 
public:
    ~SocialNetwork(){
        delete [] niza;
    }
 
    SocialNetwork(User ** niza = 0, int n = 0){
        this -> n = n;
        this -> niza = new User*[n];
 
        for (int i = 0; i < n; i++)
            this -> niza[i] = niza[i];
    }
 
    SocialNetwork & operator += (User *k){
        if (n <= max - 1){
        User ** temp = new User*[n + 1];
        for (int i = 0; i < n; i++){
            temp[i] = niza[i];
        }
            temp[n++] = k;
 
        delete [] niza;
        niza = new User*[n];
        niza = temp;
        }
        else
            throw MaximumSizeLimit(max);
 
        return *this;
    }
 
    double avgPopularity(){
        double total = 0;
        for (int i = 0; i < n; i++)
            total += niza[i] -> popularity();
            total /= n;
 
        return total;
    }
 
    static void changeMaximumSize(int k){
        max = k;
    }
};
 
int SocialNetwork :: max = 5;
 
int main() {
 
  SocialNetwork network = SocialNetwork();
    int n;
    cin >> n;
    char username[50];
    char password[50];
    char email[50];
    int userType;
    for (int i=0; i < n; ++i) {
      cin >> username;
      cin >> password;
      cin >> email;
      cin >> userType;
 
      if (userType == 1) {
        int friends;
        int likes;
        int comments;
        cin >> friends >> likes >> comments;
 
        // TODO: Try-catch
        try{
        User * u = new FacebookUser(username,password,email,friends,likes,comments);
        network += u;
        }
        catch(InvalidPassword invalid){
            invalid.print();
      }
        catch(InvalidEmail invalid){
            invalid.print();
        }
        catch(MaximumSizeLimit invalid){
            invalid.print();
        }
      }
      else {
        int followers;
        int tweets;
        cin >> followers >> tweets;
 
        // TODO: Try-catch
        try{
        User * u= new TwitterUser(username,password,email,followers,tweets);
        network += u;
        }
        catch(InvalidPassword invalid){
            invalid.print();
        }
        catch(InvalidEmail invalid){
            invalid.print();
        }
        catch(MaximumSizeLimit invalid){
            invalid.print();
        }
      }
 
 
    }
    network.changeMaximumSize(6);
    cin >> username;
    cin >> password;
    cin >> email;
    int followers;
    int tweets;
    cin >> followers >> tweets;
 
    // TODO: Try-catch
    try {
    User * u= new TwitterUser(username,password,email,followers,tweets);
    network += u;
    }
    catch(InvalidPassword invalid){
            invalid.print();
        }
        catch(InvalidEmail invalid){
            invalid.print();
      }
    catch(MaximumSizeLimit invalid){
            invalid.print();
        }
    cout << network.avgPopularity();
 
}

/*
Да се дефинира апстрактна класа User за која ќе се чуваат:

username (char[50])
password (char[50])
email (char[50])
Класата треба да содржи еден чист виртуелен метод double popularity().

Од оваа класа да се изведат две класи и тоа FacebookUser и TwitterUser.

За класата FacebookUser уште се чуваат и:

број на пријатели
број на лајкови и
број на коментари
Популарноста се пресметува така што се собираат бројот на пријатели, бројот на лајкови и бројот на коментари, но притоа бројот на лајкови се множи со коефициент на вредност на лајкот кој е ист за секој корисник и изнесува 0.1, а исто така и бројот на коментари се множи со ист таков коефициент кој е 0.5.

За класата TwitterUser уште се чуваат и:

број на следачи и
број на твитови
Популарноста се пресметува така што се собираат бројот на следачи и бројот на твитови, но притоа бројот на твитови се множи со коефициент на вредност на твитот кој е ист за секој корисник и изнесува 0.5.

Да се креира класа SocialNetwork која ќе содржи:

динамичка низа од покажувачи од класата User
број на тековни корисници и
максимален број на корисници кој може да го содржи мрежата и кој е ист за сите мрежи и иницијално е поставен на 5
Да се преоптовари операторот += со кој ќе се додава нов корисник.

Да се дефинира метод avgPopularity() кој ќе ја враќа просечната популарност на корисниците во мрежата.

Исто така да се овозможи промена на максималната големина на низата преку методот changeMaximumSize(int number).

Потребно е да се справите со следните исклучоци:

Доколку лозинката на корисникот не содржи барем 1 голема буква, 1 мала буква и 1 број да се фрли исклучок од класа InvalidPassword така што како параметар ќе се прати пораката Password is too weak.
Доколку емаилот на корисникот не содржи точно еднаш @ да се фрли исклучок од класа InvalidEmail така што како параметар ќе се прати пораката Mail is not valid.
Доколку проба да се додаде корисник во социјалната мрежа, а веќе максималниот број на корисници е пополнет да се фрли исклучок од класа MaximumSizeLimit така што како параметар ќе се прати максималниот број на корисници во мрежата.
Сите класи кои се справуваат со исклучоци треба да го имаат имплементирано методот void message() така што за првите две класи ќе ја печати пораката којашто е испратена како параметар, а за последната класа ќе печати You can't add more than N users, каде што N е параметарот кој е пратен.
 Исто така со try-catch блокови справете се со исклучоците на соодветните места во main(), каде што во catch ќе го повикате методот message() од соодветниот исклучок.
*/








#include <iostream>
#include <cstring>

using namespace std;

/* exceptions */
class InvalidPassword{
public:
    void message(){
        cout<<"Password is too weak."<<endl;
    }
};

class InvalidEmail{
public:
    void message(){
        cout<<"Mail is not valid."<<endl;
    }
};

class MaximumSizeLimit{
int n;
public:
    MaximumSizeLimit(int n){
        this->n=n;
    }
    void message(){
        cout<<"You can't add more than "<<n<<" users."<<endl;
    }
};

// KLASI 

class User
{
protected:
    char username[50];
    char password[50];
    char email[50];
    // proverki
    int isvalidpass(char *password)
    {
        int upper=0, lower=0, number=0;
        for(int i =0; i<strlen(password); i++)
        {
            if(isupper(password[i]))
                upper++;
            else if(islower(password[i]))
                lower++;
                else if(isdigit(password[i]))
                number++;
        }
        if(upper!=0 && lower != 0 && number != 0) return 1;
        else return 0;
    };
    int isvalidemail(char *email)
    {
        int counter = 0;
        for(int i =0; i<strlen(email); i++) {
            if(email[i] == '@')
                counter++;
        }
        if(counter == 1) return 1;
        else return 0;
    };
    // ***

public:
    User(const char *username = "", const char *password = "", const char *email = "")
    {
         if(isvalidpass(password)==0)
            throw InvalidPassword();
        if(isvalidemail(email)==0)
            throw InvalidEmail();
        strcpy(this->username, username);
        strcpy(this->password, password);
        strcpy(this->email, email);
    };

    virtual double popularity() = 0;
};

class FacebookUser : public User
{
private:
    int friends;
    int likes;
    int comments;

public:
    static double c_like;
    static double c_comment;
    FacebookUser(const char *username = "", const char *password = "", const char *email = "", int friends = 0, int likes = 0, int comments = 0)
        : User(username, password, email)
    {
        this->friends = friends;
        this->likes = likes;
        this->comments = comments;
    }
    double popularity(){
        return ((double)likes * c_like) + ((double)comments * c_comment) + friends;}
};
 double FacebookUser::c_like = 0.1;
 double FacebookUser::c_comment = 0.5;

    class TwitterUser : public User
{
private:
    int followers;
    int tweets;

public:
    static double c_tweet;
    TwitterUser(const char *username = "", const char *password = "", const char *email = "", int followers = 0, int tweets = 0)
        : User(username, password, email)
    {
        this->followers = followers;
        this->tweets = tweets;
    };
    double popularity()
    {
        return followers + ((double)tweets * c_tweet);
    };
};
double TwitterUser::c_tweet = 0.5;

class SocialNetwork
{
    private:
    User **array_users;
    int n_users;
    public:
   static int max_users;
   SocialNetwork()
   {
       this->array_users= new User*[0];
       this->array_users = 0;
       this->n_users = 0;
   }
    
   static void changeMaximumSize(int number)
   {
      max_users = number; 
   }
    
   double avgPopularity() //ја враќа просечната популарност на корисниците во мрежата.
   {
      double total = 0;
       for(int i = 0; i<n_users; i++)
           total += array_users[i]->popularity();
       return total/(double)n_users;
   };
   void operator += (User *u) //ќе се додава нов корисник.
   {
       if(n_users == max_users) throw MaximumSizeLimit(5);
       else {
       User **temp = new User*[n_users+1];
       for(int i = 0; i< n_users; i++)
           temp[i] = array_users[i]; // site useri stavi gi vo ovaa temp
       temp[n_users++] = u; // istata zgolemi ja za noviot
       delete [] array_users;
       array_users = temp;
       }
   }
   
    
   
};

 int SocialNetwork::max_users=5;


int main() {
/*
  SocialNetwork network = SocialNetwork();
    int n;
    cin >> n;
    char username[50];
    char password[50];
    char email[50];
    int userType;
    for (int i=0; i < n; ++i) {
      cin >> username;
      cin >> password;
      cin >> email;
      cin >> userType;
      if (userType == 1) {
        int friends;
        int likes;
        int comments;
        cin >> friends >> likes >> comments;
          
          try{
        User * u = new FacebookUser(username,password,email,friends,likes,comments);
        network += u;
          }
          catch (InvalidEmail &e)
          {
              e.message();
          }
           catch (InvalidPassword &e)
          {
              e.message();
          }
           catch (MaximumSizeLimit &e)
          {
              e.message();
          }
          
      }
      else {
        int followers;
        int tweets;
        cin >> followers >> tweets;
          
          try{ 
        User * u= new TwitterUser(username,password,email,followers,tweets);
        network += u;
          }
          catch (InvalidEmail &e){
          e.message();
          }
           catch (InvalidPassword &e)
          {
              e.message();
          }
           catch (MazimumSizeLimit &e)
          {
              e.message();
          }
      }

    }
    network.changeMaximumSize(6);
    cin >> username;
    cin >> password;
    cin >> email;
    int followers;
    int tweets;
    cin >> followers >> tweets;
    
    try {
    User * u= new TwitterUser(username,password,email,followers,tweets);
    network += u;
    }
    catch(InvalidEmail &e){
        e.message();
    }
     catch (InvalidPassword &e)
          {
              e.message();
          }
     catch (MaximumSizeLimit &e)
          {
              e.message();
          }
    cout << network.avgPopularity();*/

}
