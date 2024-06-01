#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

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
    std::cout << "Digite o codigo da cidade: ";
    std::cin >> cidade.codigo;
    std::cout << "Digite o nome da cidade: ";
    std::cin.ignore();
    std::getline(std::cin, cidade.nome);
    std::cout << "Digite a UF da cidade: ";
    std::cin >> cidade.UF;
    return cidade;
}

Especialidades lerEspecialidade() {
    Especialidades especialidade;
    std::cout << "Digite o codigo da especialidade: ";
    std::cin >> especialidade.codigo1;
    std::cout << "Digite a descricao da especialidade: ";
    std::cin.ignore();
    std::getline(std::cin, especialidade.descricao);
    return especialidade;
}

Medicos lerMedico() {
    // Declare the function buscarDescricaoEspecialidade
    void buscarDescricaoEspecialidade(std::vector<Especialidades>& especialidades, int codigo_especialidade);

    Medicos medico;
    std::cout << "Digite o codigo do medico: ";
    std::cin >> medico.codigo2;
    std::cout << "Digite o nome do medico: ";
    
   
    std::cout << "Digite o endereco do medico: ";
    std::cin.ignore();
    std::getline(std::cin, medico.endereco);
    std::cout << "Digite o telefone do medico: ";
    std::cin >> medico.telefone;
    std::cout << "Digite o codigo da cidade: ";
    std::cin >> medico.codigo_cidade;
    return medico;
}

Pacientes lerPaciente() {
    Pacientes paciente;
    std::cout << "Digite o CPF do paciente: ";
    std::cin >> paciente.CPF;
    std::cout << "Digite o nome do paciente: ";
    std::cin.ignore();
    std::getline(std::cin, paciente.nome);
    std::cout << "Digite o endereco do paciente: ";
    std::getline(std::cin, paciente.endereco);
    std::cout << "Digite o codigo da cidade: ";
    std::cin >> paciente.codigo_cidade;
    return paciente;
}

CID lerCID() {
    CID cid;
    std::cout << "Digite o codigo do CID: ";
    std::cin >> cid.codigo3;
    std::cout << "Digite a descricao do CID: ";
    std::cin.ignore();
    std::getline(std::cin, cid.descricaoc);
    return cid;
}

Medicamentos lerMedicamento() {
    Medicamentos medicamento;
    std::cout << "Digite o codigo do medicamento: ";
    std::cin >> medicamento.codigo;
    std::cout << "Digite a descricao do medicamento: ";
    std::cin.ignore();
    std::getline(std::cin, medicamento.descricao);
    std::cout << "Digite a quantidade em estoque: ";
    std::cin >> medicamento.quant_estoque;
    std::cout << "Digite o estoque minimo: ";
    std::cin >> medicamento.estoque_minimo;
    std::cout << "Digite o estoque maximo: ";
    std::cin >> medicamento.estoque_maximo;
    std::cout << "Digite o preco unitario: ";
    std::cin >> medicamento.preco_unitario;
    return medicamento;
}

Consultas lerConsulta() {
    Consultas consulta;
    std::cout << "Digite o CPF do paciente: ";
    std::cin >> consulta.CPF;
    std::cout << "Digite o codigo do médico: ";
    std::cin >> consulta.cod_medico;
    std::cout << "Digite a data da consulta (YYYY-MM-DD): ";
    std::cin >> consulta.data;
    std::cout << "Digite o horario da consulta (HH:MM): ";
    std::cin >> consulta.horario;
    std::cout << "Digite o codigo do CID: ";
    std::cin >> consulta.cod_CID;
    std::cout << "Digite o codigo do medicamento: ";
    std::cin >> consulta.cod_medicamento;
    std::cout << "Digite a quantidade do medicamento: ";
    std::cin >> consulta.qtde_medicamento;
    return consulta;
}

// Funções para exibir dados
void mostrarCidades(const std::vector<Cidades>& cidades) {
    std::cout << "Cidades:\n";
    for (const auto& cidade : cidades) {
        std::cout << "Codigo: " << cidade.codigo << ", Nome: " << cidade.nome << ", UF: " << cidade.UF << std::endl;
    }
}

void mostrarEspecialidades(const std::vector<Especialidades>& especialidades) {
    std::cout << "Especialidades:\n";
    for (const auto& especialidade : especialidades) {
        std::cout << "Codigo: " << especialidade.codigo1 << ", Descricao: " << especialidade.descricao << std::endl;
    }
}

void mostrarMedicos(const std::vector<Medicos>& medicos) {
    std::cout << "Medicos:\n";
    for (const auto& medico : medicos) {
        std::cout << "Codigo: " << medico.codigo2 << ", Nome: " << medico.nome << ", Codigo Especialidade: " << medico.codigo_especialidade 
                  << ", Endereco: " << medico.endereco << ", Telefone: " << medico.telefone << ", Codigo Cidade: " << medico.codigo_cidade << std::endl;
    }
}

void mostrarPacientes(const std::vector<Pacientes>& pacientes) {
    std::cout << "Pacientes:\n";
    for (const auto& paciente : pacientes) {
        std::cout << "CPF: " << paciente.CPF << ", Nome: " << paciente.nome << ", Endereco: " << paciente.endereco << ", Codigo Cidade: " << paciente.codigo_cidade << std::endl;
    }
}

void mostrarCID(const std::vector<CID>& doencas) {
    std::cout << "CID:\n";
    for (const auto& doenca : doencas) {
        std::cout << "Codigo: " << doenca.codigo3 << ", Descricao: " << doenca.descricaoc << std::endl;
    }
}

void mostrarMedicamentos(const std::vector<Medicamentos>& medicines) {
    std::cout << "Medicamentos:\n";
    for (const auto& medicine : medicines) {
        std::cout << "Codigo: " << medicine.codigo << ", Descricao: " << medicine.descricao << ", Quantidade em estoque: " << medicine.quant_estoque 
                  << ", Estoque minimo: " << medicine.estoque_minimo << ", Estoque maximo: " << medicine.estoque_maximo << ", Preco unitario: " << medicine.preco_unitario << std::endl;
    }
}

void mostrarConsultas(const std::vector<Consultas>& consultas) {
    std::cout << "Consultas:\n";
    for (const auto& consulta : consultas) {
        std::cout << "CPF do Paciente: " << consulta.CPF << ", Codigo do Medico: " << consulta.cod_medico << ", Data: " << consulta.data 
                  << ", Horario: " << consulta.horario << ", Codigo do CID: " << consulta.cod_CID << ", Codigo do Medicamento: " << consulta.cod_medicamento 
                  << ", Quantidade do Medicamento: " << consulta.qtde_medicamento << std::endl;
    }
}

// Funções para adicionar dados com verificação de duplicação
void adicionarCidade(std::vector<Cidades>& cidades) {
    Cidades novaCidade = lerCidade();
    auto it = std::find_if(cidades.begin(), cidades.end(), [&novaCidade](const Cidades& cidade) {
        return cidade.codigo == novaCidade.codigo;
    });
    if (it == cidades.end()) {
        cidades.push_back(novaCidade);
        std::cout << "Cidade adicionada com sucesso!\n";
    } else {
        std::cout << "Codigo da cidade ja existente!\n";
    }
}

void adicionarEspecialidade(std::vector<Especialidades>& especialidades) {
    Especialidades novaEspecialidade = lerEspecialidade();
    auto it = std::find_if(especialidades.begin(), especialidades.end(), [&novaEspecialidade](const Especialidades& especialidade) {
        return especialidade.codigo1 == novaEspecialidade.codigo1;
    });
    if (it == especialidades.end()) {
        especialidades.push_back(novaEspecialidade);
        std::cout << "Especialidade adicionada com sucesso!\n";
    } else {
        std::cout << "Codigo da especialidade ja existente!\n";
    }
}

void adicionarMedico(std::vector<Medicos>& medicos) {
    Medicos novoMedico = lerMedico();
    auto it = std::find_if(medicos.begin(), medicos.end(), [&novoMedico](const Medicos& medico) {
        return medico.nome == novoMedico.nome;
    });
    if (it == medicos.end()) {
        medicos.push_back(novoMedico);
        std::cout << "Medico adicionado com sucesso!\n";
    } else {
        std::cout << "Nome do medico ja existente!\n";
    }
}


void adicionarPaciente(std::vector<Pacientes>& pacientes) {
    Pacientes novoPaciente = lerPaciente();
    auto it = std::find_if(pacientes.begin(), pacientes.end(), [&novoPaciente](const Pacientes& paciente) {
        return paciente.CPF == novoPaciente.CPF;
    });
    if (it == pacientes.end()) {
        pacientes.push_back(novoPaciente);
        std::cout << "Paciente adicionado com sucesso!\n";
    } else {
        std::cout << "CPF do paciente já existente!\n";
    }
}

void adicionarCID(std::vector<CID>& doencas) {
    CID novoCID = lerCID();
    auto it = std::find_if(doencas.begin(), doencas.end(), [&novoCID](const CID& cid) {
        return cid.codigo3 == novoCID.codigo3;
    });
    if (it == doencas.end()) {
        doencas.push_back(novoCID);
        std::cout << "CID adicionado com sucesso!\n";
    } else {
        std::cout << "Código do CID já existente!\n";
    }
}
void buscarDescricaoEspecialidade(const std::vector<Especialidades>& especialidades, int codigoEspecialidade) {
    auto it = std::find_if(especialidades.begin(), especialidades.end(), [codigoEspecialidade](const Especialidades& especialidade) {
        return especialidade.codigo1 == codigoEspecialidade;
    });
    if (it != especialidades.end()) {
        std::cout << "Descricao da especialidade: " << it->descricao << std::endl;
    } else {
        std::cout << "Especialidade nao encontrada!\n";
    }
}
void adicionarMedicamento(std::vector<Medicamentos>& medicines) {
    Medicamentos novoMedicamento = lerMedicamento();
    auto it = std::find_if(medicines.begin(), medicines.end(), [&novoMedicamento](const Medicamentos& medicine) {
        return medicine.codigo == novoMedicamento.codigo;
    });
    if (it == medicines.end()) {
        medicines.push_back(novoMedicamento);
        std::cout << "Medicamento adicionado com sucesso!\n";
    } else {
        std::cout << "Codigo do medicamento ja existente!\n";
    }
}

// Menu principal
int main() {
    std::vector<Cidades> cidades = {
        {1, "Assis", "SP"}, {2, "Candido Mota", "SP"}, {3, "Londrina", "PR"}, {4, "Esteio", "RS"}, {5, "Xanxere", "SC"}
    };

    std::vector<Especialidades> especialidades = {
        {1, "Oftalmologia"}, {2, "Cardiologista"}, {3, "Generalista"}, {4, "Pediatria"}, {5, "Psiquiatria"}
    };

    std::vector<Medicos> medicos = {
        {1, "Dr. Carlos", 1, "Rua 1, 123", "1234-5678", 1},
        {2, "Dr. Joao", 2, "Rua 2, 456", "1234-5678", 2},
        {3, "Dr. Pedro", 3, "Rua 3, 789", "1234-5678", 3},
        {4, "Dra. Maria", 4, "Rua 4, 012", "1234-5678", 4},
        {5, "Dr. Marcos", 5, "Rua 5, 345", "1234-5678", 5}
    };

    std::vector<Pacientes> pacientes = {
        {33666790003, "Carlos Felipe", "Travessa Antonio Ferreira, 123", 1},
        {24880474061, "Luis Guilherme", "Avenida Rio Branco, 420", 2},
        {44672557022, "Ana Luiza", "Rua dos Carijos, 1024", 3},
        {33689294029, "Henrique Silva", "Rua 1, 123", 4},
        {20824063007, "Pedro Henrique", "Rua Arlindo Nogueira, 123", 5}
    };

    std::vector<CID> doencas = {
        {1, "Caxumba"}, {2, "Febre Amarela"}, {3, "Gripe"}, {4, "Dengue"}, {5, "Covid"}
    };

    std::vector<Medicamentos> medicines = {
        {1, "Penicilina", 100, 50, 200, 50.0},
        {2, "Aspirina", 50, 25, 100, 60.0},
        {3, "Losartana", 75, 30, 150, 70.0},
        {4, "Rivotril", 120, 60, 200, 80.0},
        {5, "Omeprazol", 80, 40, 160, 90.0}
    };

    std::vector<Consultas> consultas = {
        {33666790003, 1, "2022-01-01", "10:00", 3, 2, 10},
        {24880474061, 2, "2022-01-02", "14:00", 2, 1, 5},
        {44672557022, 3, "2022-01-03", "08:00", 1, 3, 8},
        {33689294029, 1, "2022-01-04", "12:00", 5, 4, 3},
        {20824063007, 2, "2022-01-05", "16:00", 4, 5, 7}
    };

    int opcao;
    do {
        std::cout << "Menu Principal:\n";
        std::cout << "1. Mostrar Cidades\n";
        std::cout << "2. Mostrar Especialidades\n";
        std::cout << "3. Mostrar Medicos\n";
        std::cout << "4. Mostrar Pacientes\n";
        std::cout << "5. Mostrar CID\n";
        std::cout << "6. Mostrar Medicamentos\n";
        std::cout << "7. Mostrar Consultas\n";
        std::cout << "8. Adicionar Cidade\n";
        std::cout << "9. Adicionar Especialidade\n";
        std::cout << "10. Adicionar Medico\n";
        std::cout << "11. Adicionar Paciente\n";
        std::cout << "12. Adicionar CID\n";
        std::cout << "13. Adicionar Medicamento\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                mostrarCidades(cidades);
                break;
            case 2:
                mostrarEspecialidades(especialidades);
                break;\
            case 3:
                mostrarMedicos(medicos);
                break;
            case 4:
                mostrarPacientes(pacientes);
                break;
            case 5:
                mostrarCID(doencas);
                break;
            case 6:
                mostrarMedicamentos(medicines);
                break;
            case 7:
                mostrarConsultas(consultas);
                break;
            case 8:
                adicionarCidade(cidades);
                break;
            case 9:
                adicionarEspecialidade(especialidades);
                break;
            case 10:
                adicionarMedico(medicos);
                break;
            case 11:
                adicionarPaciente(pacientes);
                break;
            case 12:
                adicionarCID(doencas);
                break;
            case 13:
                adicionarMedicamento(medicines);
                break;
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opcao inválida!\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}
