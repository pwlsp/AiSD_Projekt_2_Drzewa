#include <iostream>
#include <fstream>
#include <string>
#include <random>

void generate(int N){
    std::string nazwa = "data_" + std::to_string(N) + ".txt";
    std::fstream plik;
    plik.open(nazwa, std::ios::out | std::ios::trunc);
    plik << N << "\n";
    for(int i = 0; i < N; i++){
        plik << rand() % N << " ";
    }
    plik << "\nMinMax\nPrint\nRebalance\nExit\n";
    plik.close();
}

int main(){
    //od 2^11 = 2048 do 2^16 = 65536
    std::cout << "ok";
    for(int i = 2048; i <= 65536; i *= 4) generate(i);
    return 0;
}