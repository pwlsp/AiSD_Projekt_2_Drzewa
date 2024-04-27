#include <iostream>
#include <fstream>
#include <string>
#include <random>

void generate_random(int N){
    std::string nazwa = "data_random" + std::to_string(N) + ".txt"; //to jest do AVL i uśrednienia bst
    std::fstream plik;
    plik.open(nazwa, std::ios::out | std::ios::trunc);
    plik << N << "\n";
    for(int i = 0; i < N; i++){
        plik << rand() % N << " ";
    }
    plik << "\nMinMax\nPrint\nRebalance\nExit\n";
    plik.close();
}

void generate_degenerate(int N){
    std::string nazwa = "data_bst_degenerate_increasing" + std::to_string(N) + ".txt"; //to jest do bst
    std::fstream plik1, plik2;
    plik1.open(nazwa, std::ios::out | std::ios::trunc);
    plik1 << N << "\n";
    for(int i = 0; i < N; i++){
        plik1 << i << " ";
    }
    plik1 << "\nMinMax\nPrint\nRebalance\nExit\n";
    plik1.close();
    nazwa = "data_bst_degenerate_decreasing" + std::to_string(N) + ".txt"; 
    plik2.open(nazwa, std::ios::out | std::ios::trunc);
    plik2 << N << "\n";
    for(int i = N; i > 0; i--){
        plik2 << i << " ";
    }
    plik2 << "\nMinMax\nPrint\nRebalance\nExit\n";
    plik2.close();
}

int main(){
    for(int i = 2048; i <= 65536; i *= 2) generate_random(i);
    for(int i = 2048; i <= 65536; i *= 2) generate_degenerate(i);
    return 0;
}