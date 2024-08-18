#include <iostream>
#include <vector>
using namespace std;

class FilaNormal {
public:
  string *pacientes;
  int frente;
  int fim;

  FilaNormal() {
    pacientes = new string[50];
    frente = 0;
    fim = 0;
  }

  ~FilaNormal() { delete[] pacientes; }

  void adicionar(string nome);
  void atender();
  void verificar();
};

class FilaPreferencial {
public:
  string *pacientes;
  int frente;
  int fim;

  FilaPreferencial() {
    pacientes = new string[50];
    frente = 0;
    fim = 0;
  }

  ~FilaPreferencial() { delete[] pacientes; }

  void adicionar(string nome);
  void atender();
  void verificar();
};

void FilaNormal::adicionar(string nome) {
  pacientes[fim] = nome;
  fim++;
  cout << "Paciente " << nome << " (Normal) adicionado à fila." << endl;
}

void FilaNormal::atender() {
  if (fim == 0) {
    cout << "Nenhum paciente na fila." << endl;
    return;
  }

  cout << "Paciente " << pacientes[frente] << " (Normal) foi atendido" << endl;

  string *vetorAuxiliar = new string[fim - 1];
  for (int i = 0; i < fim - 1; i++) {
    vetorAuxiliar[i] = pacientes[i + 1];
  }

  pacientes = vetorAuxiliar;

  fim--;

  if (fim == 0) {
    frente = 0;
  }
}

void FilaNormal::verificar() {
  cout << "Fila Normal: ";
  for (int i = 0; i < fim; i++) {
    cout << pacientes[i];
    if (i != (fim - 1)) {
      cout << ", ";
    }
  }
  cout << endl;
}

void FilaPreferencial::adicionar(string nome) {
  pacientes[fim] = nome;
  fim++;
  cout << "Paciente " << nome << " (Prioritário) adicionado à fila." << endl;
}

void FilaPreferencial::atender() {
  if (fim == 0) {
    cout << "Nenhum paciente na fila." << endl;
    return;
  }

  cout << "Paciente " << pacientes[frente] << " (Prioritário) foi atendido" << endl;

  string *vetorAuxiliar = new string[fim - 1];
  for (int i = 0; i < fim - 1; i++) {
    vetorAuxiliar[i] = pacientes[i + 1];
  }

  pacientes = vetorAuxiliar;

  fim--;

  if (fim == 0) {
    frente = 0;
  }
}

void FilaPreferencial::verificar() {
  cout << "Fila Prioritária: ";
  for (int i = 0; i < fim; i++) {
    cout << pacientes[i];
    if (i != (fim - 1)) {
      cout << ", ";
    }
  }
  cout << endl;
}
