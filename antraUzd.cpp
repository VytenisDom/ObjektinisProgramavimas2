#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
struct mokinys {
    string vardas;
    string pavarde;
    double egzaminas;
    vector<double> nd;
    double vidurkis;
    double mediana;
};
double getAverage(vector<mokinys> p, int index) {
    double sum = 0;
    for(int i=0; i<p[index].nd.size(); i++){
        sum+=p[index].nd[i];
    }
    return sum/p.size();
}
double getMedian(vector<mokinys> p, int index) {
    int n = p[index].nd.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[index].nd[i]<p[index].nd[j]){
                double temp = p[index].nd[i];
                p[index].nd[i] = p[index].nd[j];
                p[index].nd[j] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<p[index].nd[i]<<endl;
    }
    if(n%2 == 1){
        return p[index].nd[n/2];
    } else {
        return (p[index].nd[n/2] + p[index].nd[(n/2)-1]) / 2;
    }
}
void writeEverything(vector<mokinys> p) {
    p.pop_back();
    cout<<endl;
    for(int i=0;i<p.size(); i++){
        cout<<"Vardas : "<<p[i].vardas<<endl;
        cout<<"Pavarde : "<<p[i].pavarde<<endl;
        cout<<"Vidurkis : "<<fixed<<setprecision(2)<<p[i].vidurkis<<endl;
        cout<<"Mediana : "<<p[i].mediana<<endl;
        cout<<"Egzamino Rezultatas : "<<p[i].egzaminas<<endl;
    }
}
int main() {
    vector<mokinys> p;
    string value;
    double value_d;
    for(int i=0;; i++){
        p.push_back(mokinys());
        cout<<"Iveskite "<<i+1<<" mokinio varda"<<endl;
        cin>>value;
        if(value != "0") {
            p[i].vardas = value;
        } else {
            break;
        }
        cout<<"Iveskite "<<i+1<<" mokinio pavarde"<<endl;
        cin>>value;
        if(value != "0") {
            p[i].pavarde = value;
        } else {
            break;
        }
        for(int j=0;; j++){
            cout<<"Iveskite "<<i+1<<" mokinio "<<j<<" namu darbo rezultata"<<endl;
            cin>>value_d;
            if(value_d != 0) {
                p[i].nd.push_back(double());
                p[i].nd[j] = value_d;
            } else {
                break;
            }
        }
        cout<<"Iveskite "<<i+1<<" mokinio egzamino rezultata"<<endl;
        cin>>value_d;
        if(value_d != 0) {
            p[i].egzaminas = value_d;
        } else {
            break;
        }

        p[i].vidurkis = getAverage(p, i);
        p[i].mediana = getMedian(p, i);
    }
    writeEverything(p);
}
