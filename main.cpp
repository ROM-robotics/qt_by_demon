#include <QTextStream>
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <QStorageInfo>


QTextStream cout(stdout);
QTextStream cerr (stderr);
int lucky = 7 ;
int luck2;
float pi = 3.14;
double e = 2.17;
int main(){
QString str , newstr;
QTextStream strbuf (&str);
cout << "An in memory stram " << endl ;    
    strbuf << "luckynumber : " << lucky << endl 
    << "pi : " << pi << endl  
    << "e : " << e << endl ;
    cout << str;
    QFile data("data.txt");

    data.open (QIODevice::WriteOnly);
    QTextStream out (&data);
    out << str ;
    data.close();

    cout << "Read data from the file - watch for errors ." << endl;
    
    
    if ( data.open (QIODevice:: ReadOnly) ) {
      QTextStream in (&data);
     int lucky2;
      in >> newstr >> lucky2 ;
     if (lucky != lucky2){
    cerr << "Error! Wrong " << newstr << lucky2 << endl; }
    else {
    cout << newstr << " OK " << endl ;}
    

    float pi2 ;
    in >> newstr >> pi2;
    if (pi2 != pi ){
    cerr << "Error Wrong " << newstr << pi2 << endl;}
    else {cout << newstr << " Ok" << endl;}
    double e2;
    in >> newstr >> e2 ;
    if (e2 != e ){
        cerr << "Error: Wrong " << newstr << e2 << endl;
    } 
    else 
      cout << newstr << " Ok " << endl;
        data.close();


    } 
    cout << "Read from file line-by-line" << endl;
    if (data.open (QIODevice::ReadOnly)){

        QTextStream in(&data);
        while (not in.atEnd()){

            newstr = in.readLine();
            cout << newstr << endl;
        }
        data.close();
    } 
  

    return 0;
}
