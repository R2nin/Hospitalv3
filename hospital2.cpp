#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Definição das estruturas
struct Cidades {
    int codigo;
    std::string nome;
    std::string UF;
};

struct Especialidades {
    int codigo1;
    std::string descricao;
};

struct Medicos {
    int codigo2;
    std::string nome;
    int codigo_especialidade;
    std::string endereco;
    std::string telefone;
    int codigo_cidade;
};

struct Pacientes {
    long long CPF;
    std::string nome;
    std::string endereco;
    int codigo_cidade;
};

struct CID {
    int codigo3;
    std::string descricaoc;
};

struct Medicamentos {
    int codigo;
    std::string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    double preco_unitario;
};

struct Consultas {
    long long CPF;
    int cod_medico;
    std::string data;
    std::string horario;
    int cod_CID;
    int cod_medicamento;
    int qtde_medicamento;
};

// Funções para leitura de dados
Cidades lerCidade() {
    Cidades cidade;
    // Implemente a leitura dos dados de uma cidade
    return cidade;
}

Especialidades lerEspecialidade() {
    Especialidades especialidade;
    // Implemente a leitura dos dados de uma especialidade
    return especialidade;
}

Medicos lerMedico() {
    Medicos medico;
    // Implemente a leitura dos dados de um médico
    return medico;
}

Pacientes lerPaciente() {
    Pacientes paciente;
    // Implemente a leitura dos dados de um paciente
    return paciente;
}

CID lerCID() {
    CID cid;
    // Implemente a leitura dos dados de um CID
    return cid;
}

Medicamentos lerMedicamento() {
    Medicamentos medicamento;
    // Implemente a leitura dos dados de um medicamento
    return medicamento;
}

Consultas lerConsulta() {
    Consultas consulta;
    // Implemente a leitura dos dados de uma consulta
    return consulta;
}


int main(){
   
    // Inicializando a estrutura Cidades com os dados fornecidos
    std::vector<Cidades> cidades;

    // Dados das cidades
    Cidades cidade1 = {1, "Assis", "SP"};
    Cidades cidade2 = {2, "Candido Mota", "SP"};
    Cidades cidade3 = {3, "Londrina", "PR"};
    Cidades cidade4 = {4, "Esteio", "RS"};
    Cidades cidade5 = {5, "Xanxere", "SC"};
    // Adicionando as cidades ao vetor de cidades
    cidades.push_back(cidade1);
    cidades.push_back(cidade2);
    cidades.push_back(cidade3);
    cidades.push_back(cidade4);
    cidades.push_back(cidade5);
    // Exemplo de como acessar os dados das cidades
    std::cout << "---------------------------------------------------------------------------";
    std::cout << "\n";
    for (const auto& cidade : cidades) {
        std::cout << "Codigo: " << cidade.codigo << ", Nome: " << cidade.nome << ", UF: " << cidade.UF << std::endl;
    }
    std::cout << "\n";

    // Inicializando a estrutura Especialidades com os dados fornecidos
   
    std::vector<Especialidades> especialidades;

    // Dados das Especialidades
    Especialidades especialidade1 = {1, "Oftalmologia"};
    Especialidades especialidade2 = {2, "Cardiologista"};
    Especialidades especialidade3 = {3, "Generalista"};
    Especialidades especialidade4 = {4, "Pediatria"};
    Especialidades especialidade5 = {5, "Psiquiatria"};
    // Adicionando as especialidades ao vetor especialidade
    especialidades.push_back(especialidade1);
    especialidades.push_back(especialidade2);
    especialidades.push_back(especialidade3);
    especialidades.push_back(especialidade4);
    especialidades.push_back(especialidade5);
    // Exemplo de como acessar os dados das especialidades
    
    for (const auto& especialidade : especialidades) {
        std::cout << "Codigo da Especialidade: " << especialidade.codigo1 << ", Especialidade: " << especialidade.descricao << std::endl;
    }
   std::cout << "---------------------------------------------------------------------------";
    std::cout << "\n";

    // Inicializando a estrutura medicos com os dados fornecidos
    std::vector<Medicos> medicos;

    // Dados das medicos
    Medicos medico1 = {1, "Dr. Carlos", 1, "Rua 1, 123", "1234-5678", 1};
    Medicos medico2 = {2, "Dr. Joao", 2, "Rua 2, 456", "1234-5678", 2};
    Medicos medico3 = {3, "Dr. Pedro", 3, "Rua 3, 789", "1234-5678", 3};
    Medicos medico4 = {4, "Dra. Maria", 4, "Rua 4, 012", "1234-5678", 4};
    Medicos medico5 = {5, "Dr. Marcos", 5, "Rua 5, 345", "1234-5678", 5};
    // Adicionando as medicos ao vetor medico
    medicos.push_back(medico1);
    medicos.push_back(medico2);
    medicos.push_back(medico3);
    medicos.push_back(medico4);
    medicos.push_back(medico5);
    // Exemplo de como acessar os dados das medicos
    std::cout << "---------------------------------------------------------------------------\n\n";
    std::cout << "CADASTRO DE MEDICOS\n\n";
    for (const auto& medico : medicos) {
        std::cout << "Codigo do Medico: " << medico.codigo2<<"\n" <<"medico: " << medico.nome<<"\n" <<"Codigo Especialidade: " << medico.codigo_especialidade<<"\n" <<"Endereco: " << medico.endereco<<"\n" <<"Telefone: " << medico.telefone<<"\n" <<"Codigo Cidade: " << medico.codigo_cidade<<"\n" <<std ::endl;
    }
   std::cout << "---------------------------------------------------------------------------";
    std::cout << "\n";

     // Inicializando a estrutura pacientes com os dados fornecidos
    std::vector<Pacientes> pacientes;

    // Dados das pacientes
    Pacientes paciente1 = {33666790003, "Carlos Felipe", "Travessa Antonio Ferreira, 123", 1};
    Pacientes paciente2 = {24880474061, "Luis Guilherme", "Avenida Rio Branco, 420", 2};
    Pacientes paciente3 = {44672557022, "Ana Luiza", "Rua dos Carijos, 1024",3};
    Pacientes paciente4 = {33689294029, "Henrique Silva", "Rua 1, 123", 4};
    Pacientes paciente5 = {20824063007, "Pedro Henrique", "Rua Arlindo Nogueira, 123", 5};
    // Adicionando as medicos ao vetor paciente
    pacientes.push_back(paciente1);
    pacientes.push_back(paciente2);
    pacientes.push_back(paciente3);
    pacientes.push_back(paciente4);
    pacientes.push_back(paciente5);
    // Exemplo de como acessar os dados das pacientes
    std::cout << "---------------------------------------------------------------------------\n\n";
    std::cout << "CADASTRO DE PACIENTES\n";
    for (const auto& paciente : pacientes) {
        std::cout << "|"  << std::right << std::setw(10) <<"CPF paciente: "  << paciente.CPF <<  std::endl ;
      
        std::cout << "|"  << std::left << std::setw(10) <<"Nome paciente: " << paciente.nome << std::endl;
        std::cout << "|"  << std::left << std::setw(10) <<"Endereco: " << paciente.endereco<< std::endl;
        std::cout << "|"  << std::left << std::setw(10) <<"Codigo Cidade: " << paciente.codigo_cidade<< std::endl;
        std::cout << "\n";
    }
    std::cout << "---------------------------------------------------------------------------";
    std::cout << "---------------------------------------------------------------------------\n\n";
    std::cout << "CADASTRO DE CID\n\n";
       std::vector<CID> doencas;

    // Adicionando 5 elementos ao vetor de doenças
    doencas.push_back({1, "Caxumba"});
    doencas.push_back({3, "Febre Amarela"});
    doencas.push_back({3, "Gripe"});
    doencas.push_back({4, "Dengue"});
    doencas.push_back({5, "Covid"});
std::cout << "---------------------------------------------------------------------------\n";
    // Exibindo as doenças
    for (const auto& doenca : doencas) {
        std::cout << "Codigo: " << doenca.codigo3 << std::endl;
        std::cout << "Descricao: " << doenca.descricaoc << std::endl;
        std::cout << std::endl;
    }
       std::vector<Medicamentos> medicines;

    // Adding 5 elements to the medicines vector
    medicines.push_back({1, "Penicilina", 100, 50, 200, 50.0});
    medicines.push_back({2, "Aspirina", 50, 25, 100, 60.0});
    medicines.push_back({3, "Losartana", 75, 30, 150, 70.0});
    medicines.push_back({4, "Rivotril", 120, 60, 200, 80.0});
    medicines.push_back({5, "Omeprazol", 80, 40, 160, 90.0});

    // Displaying the medicines
    for (const auto& medicine : medicines) {
        std::cout << "Codigo: " << medicine.codigo << std::endl;
        std::cout << "Descricao: " << medicine.descricao << std::endl;
        std::cout << "Quuantidade em estoque: " << medicine.quant_estoque << std::endl;
        std::cout << "Estoque Minimo: " << medicine.estoque_minimo << std::endl;
        std::cout << "Estoque Maximo: " << medicine.estoque_maximo << std::endl;
        std::cout << "Preco Unitario: " << medicine.preco_unitario << std::endl;
        std::cout << std::endl;}
        std::cout << "---------------------------------------------------------------------------\n";
        std::vector<Consultas> consultas;

    // Adicionando 5 elementos ao vetor de consultas
    consultas.push_back({33666790003, 1, "2022-01-01", "10:00", 3, 2, 10});
    consultas.push_back({24880474061, 2, "2022-01-02", "14:00", 2, 1, 5});
    consultas.push_back({44672557022, 3, "2022-01-03", "08:00", 1, 3, 8});
    consultas.push_back({33689294029, 1, "2022-01-04", "12:00", 5, 4, 3});
    consultas.push_back({20824063007, 2, "2022-01-05", "16:00", 4, 5, 7});

    // Exibindo as consultas
    for (const auto& consulta : consultas) {
        std::cout << "CPF do Paciente: " << consulta.CPF << std::endl;
        std::cout << "Codigo do Medico: " << consulta.cod_medico << std::endl;
        std::cout << "Data: " << consulta.data << std::endl;
        std::cout << "Horario: " << consulta.horario << std::endl;
        std::cout << "Codigo da Doenca: " << consulta.cod_CID << std::endl;
        std::cout << "Codigo do Medicamento: " << consulta.cod_medicamento << std::endl;
        std::cout << "Quantidade de Medicamento: " << consulta.qtde_medicamento << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}