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
    int codigo;
    std::string descricao;
};

struct Medicos {
    int codigo;
    std::string nome;
    int codigo_especialidade;
    std::string endereco;
    std::string telefone;
    int codigo_cidade;
};

struct Pacientes {
    std::string CPF; // Corrigido para string
    std::string nome;
    std::string endereco;
    int codigo_cidade;
};

struct CID {
    int codigo;
    std::string descricao;
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
    std::string CPF; // Corrigido para string
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
    std::cin >> especialidade.codigo;
    std::cout << "Digite a descricao da especialidade: ";
    std::cin.ignore();
    std::getline(std::cin, especialidade.descricao);
    return especialidade;
}

Medicos lerMedico() {
    Medicos medico;
    std::cout << "Digite o codigo do medico: ";
    std::cin >> medico.codigo;
    std::cout << "Digite o nome do medico: ";
    std::cin.ignore();
    std::getline(std::cin, medico.nome);
    std::cout << "Digite o codigo da especialidade: ";
    std::cin >> medico.codigo_especialidade;
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
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Digite o CPF do paciente: ";
    std::getline(std::cin, paciente.CPF); // Corrigido para getline
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
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Digite o codigo do CID: ";
    std::cin >> cid.codigo;
    std::cout << "Digite a descricao do CID: ";
    std::cin.ignore();
    std::getline(std::cin, cid.descricao);
    return cid;
}

Medicamentos lerMedicamento() {
    Medicamentos medicamento;
    std::cin.clear();
    std::cin.ignore();
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
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Digite o CPF do paciente: ";
    std::getline(std::cin, consulta.CPF); // Corrigido para getline
    std::cout << "Digite o codigo do médico: ";
    std::cin >> consulta.cod_medico;
    std::cout << "Digite a data da consulta (YYYY-MM-DD): ";
    std::cin.ignore();
    std::getline(std::cin, consulta.data);
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
        std::cout << "Codigo: " << especialidade.codigo << ", Descricao: " << especialidade.descricao << std::endl;
    }
}

void mostrarMedicos(const std::vector<Medicos>& medicos) {
    std::cout << "Medicos:\n";
    for (const auto& medico : medicos) {
        std::cout << "Codigo: " << medico.codigo << ", Nome: " << medico.nome << ", Codigo Especialidade: " << medico.codigo_especialidade
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
        std::cout << "Codigo: " << doenca.codigo << ", Descricao: " << doenca.descricao << std::endl;
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
        return especialidade.codigo == novaEspecialidade.codigo;
    });
    if (it == especialidades.end()) {
        especialidades.push_back(novaEspecialidade);
        std::cout << "Especialidade adicionada com sucesso!\n";
    } else {
        std::cout << "Codigo da especialidade ja existente!\n";
    }
}

void adicionarMedicoValidado(std::vector<Medicos>& medicos, std::vector<Especialidades>& especialidades, std::vector<Cidades>& cidades) {
    Medicos novoMedico = lerMedico();

    // Verificar se o código do médico já existe
    auto it = std::find_if(medicos.begin(), medicos.end(), [&novoMedico](const Medicos& medico) {
        return medico.codigo == novoMedico.codigo;
    });

    if (it != medicos.end()) {
        std::cout << "Codigo do medico já existente! Não será possível adicionar o novo médico.\n";
        return;
    }

    // Buscar a descrição da especialidade
    auto itEspecialidade = std::find_if(especialidades.begin(), especialidades.end(), [&novoMedico](const Especialidades& especialidade) {
        return especialidade.codigo == novoMedico.codigo_especialidade;
    });

    if (itEspecialidade == especialidades.end()) {
        std::cout << "Codigo da especialidade invalido! Não será possível adicionar o novo médico.\n";
        return;
    }

    std::cout << "Descricao da especialidade: " << itEspecialidade->descricao << std::endl;

    // Buscar o nome da cidade e UF
    auto itCidade = std::find_if(cidades.begin(), cidades.end(), [&novoMedico](const Cidades& cidade) {
        return cidade.codigo == novoMedico.codigo_cidade;
    });

    if (itCidade == cidades.end()) {
        std::cout << "Codigo da cidade invalido! Não sera possivel adicionar o novo medico.\n";
        return;
    }

    std::cout << "Nome da cidade: " << itCidade->nome << ", UF: " << itCidade->UF << std::endl;

    // Adicionar o novo médico ao vetor de médicos
    medicos.push_back(novoMedico);
    std::cout << "Medico adicionado com sucesso!\n";
}

void adicionarPacienteValidado(std::vector<Pacientes>& pacientes, std::vector<Cidades>& cidades) {
    Pacientes novoPaciente = lerPaciente();

    // Verificar se o CPF do paciente ja existe
    auto it = std::find_if(pacientes.begin(), pacientes.end(), [&novoPaciente](const Pacientes& paciente) {
        return paciente.CPF == novoPaciente.CPF;
    });

    if (it != pacientes.end()) {
        std::cout << "CPF do paciente ja existente! Não sera possivel adicionar o novo paciente.\n";
        return;
    }

    // Buscar o nome da cidade e UF
    auto itCidade = std::find_if(cidades.begin(), cidades.end(), [&novoPaciente](const Cidades& cidade) {
        return cidade.codigo == novoPaciente.codigo_cidade;
    });

    if (itCidade == cidades.end()) {
        std::cout << "Codigo da cidade invalido! Não sera possivel adicionar o novo paciente.\n";
        return;
    }

    std::cout << "Nome da cidade: " << itCidade->nome << ", UF: " << itCidade->UF << std::endl;

    // Adicionar o novo paciente ao vetor de pacientes
    pacientes.push_back(novoPaciente);
    std::cout << "Paciente adicionado com sucesso!\n";
}

void adicionarCID(std::vector<CID>& doencas) {
    CID novoCID = lerCID();
    auto it = std::find_if(doencas.begin(), doencas.end(), [&novoCID](const CID& cid) {
        return cid.codigo == novoCID.codigo;
    });
    if (it == doencas.end()) {
        doencas.push_back(novoCID);
        std::cout << "CID adicionado com sucesso!\n";
    } else {
        std::cout << "Código do CID já existente!\n";
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

void excluirPacientePorNome(std::vector<Pacientes>& pacientes) {
    std::string nome;
    std::cout << "Digite o nome do paciente que deseja excluir: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    // Buscar o paciente com o nome informado
    auto it = std::find_if(pacientes.begin(), pacientes.end(), [&nome](const Pacientes& paciente) {
        return paciente.nome == nome;
    });

    if (it == pacientes.end()) {
        std::cout << "Nome do paciente nao encontrado! Nao sera possível realizar a exclusao.\n";
        return;
    }

    // Exibir informações do paciente encontrado
    std::cout << "\nPaciente encontrado:\n";
    std::cout << "CPF: " << it->CPF << ", Nome: " << it->nome << ", Endereco: " << it->endereco << ", Codigo Cidade: " << it->codigo_cidade << std::endl;

    // Confirmar a exclusão do paciente
    char confirmacao;
    std::cout << "Tem certeza que deseja excluir este paciente? (S/N): ";
    std::cin >> confirmacao;

    if (confirmacao == 'S' || confirmacao == 's') {
        // Remover o paciente do vetor de pacientes
        pacientes.erase(it);
        std::cout << "Paciente excluído com sucesso!\n";
    } else {
        std::cout << "Exclusao cancelada.\n";
    }
}

void agendarConsulta(std::vector<Pacientes>& pacientes, std::vector<Medicos>& medicos, std::vector<CID>& doencas,
                      std::vector<Medicamentos>& medicamentos, std::vector<Consultas>& consultas, std::vector<Cidades>& cidades, std::vector<Especialidades>& especialidades) {
    std::string codigo_paciente; // Corrigido para string
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Digite o CPF do paciente: ";
    std::getline(std::cin, codigo_paciente); // Corrigido para getline

    // Buscar o paciente com o CPF informado e exibir o nome do paciente e o nome da cidade e UF
    auto it_paciente = std::find_if(pacientes.begin(), pacientes.end(), [&codigo_paciente](const Pacientes& paciente) {
        return paciente.CPF == codigo_paciente;
    });

    if (it_paciente == pacientes.end()) {
        std::cout << "Paciente nao encontrado!\n";
        return;
    }

    std::cout << "Nome do paciente: " << it_paciente->nome << "\n";
    std::cout << "Endereco do paciente: " << it_paciente->endereco << "\n";

    auto it_cidade = std::find_if(cidades.begin(), cidades.end(), [it_paciente](const Cidades& cidade) {
        return cidade.codigo == it_paciente->codigo_cidade;
    });

    if (it_cidade == cidades.end()) {
        std::cout << "Codigo da cidade nao encontrado!\n";
        return;
    }

    std::cout << "Nome da cidade: " << it_cidade->nome << "\n";
    std::cout << "UF da cidade: " << it_cidade->UF << "\n";

    int codigo_medico;
    std::cout << "Digite o codigo do medico: ";
    std::cin >> codigo_medico;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Buscar o medico com o codigo informado e exibir o nome do medico e a descricao da especialidade
    auto it_medico = std::find_if(medicos.begin(), medicos.end(), [codigo_medico](const Medicos& medico) {
        return medico.codigo == codigo_medico;
    });

    if (it_medico == medicos.end()) {
        std::cout << "Codigo do medico nao encontrado!\n";
        return;
    }

    std::cout << "Nome do medico: " << it_medico->nome << "\n";
    std::cout << "Endereco do medico: " << it_medico->endereco << "\n";
    std::cout << "Telefone do medico: " << it_medico->telefone << "\n";

    auto it_especialidade = std::find_if(especialidades.begin(), especialidades.end(), [it_medico](const Especialidades& especialidade) {
        return especialidade.codigo == it_medico->codigo_especialidade;
    });

    if (it_especialidade == especialidades.end()) {
        std::cout << "Codigo da especialidade nao encontrado!\n";
        return;
    }

    std::cout << "Descricao da especialidade: " << it_especialidade->descricao << "\n";

    std::string data_consulta;
    std::cout << "Digite a data da consulta (formato: dd/mm/aaaa): ";
    std::getline(std::cin, data_consulta);

    int codigo_CID;
    std::cout << "Digite o codigo do CID: ";
    std::cin >> codigo_CID;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Buscar o CID com o codigo informado e exibir a descricao
    auto it_doenca = std::find_if(doencas.begin(), doencas.end(), [codigo_CID](const CID& doenca) {
        return doenca.codigo == codigo_CID;
    });

    if (it_doenca == doencas.end()) {
        std::cout << "Codigo do CID nao encontrado!\n";
        return;
    }

    std::cout << "Descricao do CID: " << it_doenca->descricao << "\n";

    int codigo_medicamento;
    std::cout << "Digite o codigo do medicamento: ";
    std::cin >> codigo_medicamento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Buscar o medicamento com o codigo informado e exibir a descricao
    auto it_medicamento = std::find_if(medicamentos.begin(), medicamentos.end(), [codigo_medicamento](const Medicamentos& medicamento) {
        return medicamento.codigo == codigo_medicamento;
    });

    if (it_medicamento == medicamentos.end()) {
        std::cout << "Codigo do medicamento nao encontrado!\n";
        return;
    }

    std::cout << "Descricao do medicamento: " << it_medicamento->descricao << "\n";
    std::cout << "Quantidade em estoque: " << it_medicamento->quant_estoque << "\n";
    std::cout << "Estoque minimo: " << it_medicamento->estoque_minimo << "\n";

    int qtde_medicamento;
    std::cout << "Digite a quantidade do medicamento: ";
    std::cin >> qtde_medicamento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Verificar se a quantidade de medicamento solicitada é maior que o estoque mínimo
    if (it_medicamento->quant_estoque - qtde_medicamento < it_medicamento->estoque_minimo) {
        std::cout << "Quantidade de medicamentos insuficiente. A quantidade solicitada excede o estoque minimo.\n";
        return;
    }

    // Criar um novo registro de consulta e adicionar ao vetor de consultas
    Consultas nova_consulta{ codigo_paciente, codigo_medico, data_consulta, "", codigo_CID, codigo_medicamento, qtde_medicamento };
    consultas.push_back(nova_consulta);

    // Atualizar a quantidade de medicamento em estoque
    it_medicamento->quant_estoque -= qtde_medicamento;

    std::cout << "Consulta agendada com sucesso!\n";
};
// Sugestao de compras
void sugestaoDeCompras(std::vector<Medicamentos>& medicamentos) {
    for (auto& medicamento : medicamentos) {
        if (medicamento.quant_estoque <= medicamento.estoque_minimo * 1.1) {
            std::cout << "Descricao: " << medicamento.descricao << "\n";
            std::cout << "Quantidade em estoque: " << medicamento.quant_estoque << "\n";
            std::cout << "Estoque maximo: " << medicamento.estoque_maximo << "\n";
            std::cout << "Preco unitario: " << medicamento.preco_unitario << "\n";
            std::cout << "Sugestao de compra: " << medicamento.estoque_maximo - medicamento.quant_estoque << "\n";
            std::cout << "Valor total da compra: " << (medicamento.estoque_maximo - medicamento.quant_estoque) * medicamento.preco_unitario << "\n\n";
        }
    }
}
void valorTotalArrecadado(std::vector<Consultas>& consultas, std::vector<Medicamentos>& medicamentos) {
    double valorTotal = 0.0;
    for (const auto& consulta : consultas) {
        // busca o medicamento receitado na consulta
        auto it = std::find_if(medicamentos.begin(), medicamentos.end(), [&consulta](const Medicamentos& medicamento) {
            return medicamento.codigo == consulta.cod_medicamento;
        });
        if (it != medicamentos.end()) {
            // calcula o valor do medicamento receitado
            double valorMedicamento = it->preco_unitario * consulta.qtde_medicamento;
            // soma o valor da consulta (R$100) mais o valor do medicamento ao valor total
            valorTotal += 100.0 + valorMedicamento;
        }
    }
    std::cout << "Valor total arrecadado com consultas: R$" << std::fixed << std::setprecision(2) << valorTotal << "\n";
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
        {"33666790003", "Carlos Felipe", "Travessa Antonio Ferreira, 123", 1},
        {"24880474061", "Luis Guilherme", "Avenida Rio Branco, 420", 2},
        {"44672557022", "Ana Luiza", "Rua dos Cidadaos, 456", 3},
        {"12659373085", "Juliana Silva", "Rua das Flores, 789", 4},
        {"80813033065", "Fernanda Souza", "Avenida Paulista, 1010", 5}
    };

    std::vector<CID> doencas = {
        {1, "Fratura do antebraco"}, {2, "Hemorragia nasal"}, {3, "Traumatismo superficial"}, {4, "Dor abdominal"}, {5, "Enxaqueca"}
    };

    std::vector<Medicamentos> medicines = {
        {1, "Paracetamol", 100, 20, 200, 5.50},
        {2, "Dipirona", 150, 30, 250, 3.75},
        {3, "Amoxicilina", 80, 15, 100, 15.25},
        {4, "Ibuprofeno", 120, 25, 150, 8.90},
        {5, "Dorflex", 90, 20, 120, 10.75}
    };

    std::vector<Consultas> consultas = {
        {"33666790003", 1, "2024-06-01", "09:00", 1, 1, 2},
        {"24880474061", 2, "2024-06-02", "10:00", 2, 2, 3},
        {"44672557022", 3, "2024-06-03", "11:00", 3, 3, 4},
        {"12659373085", 4, "2024-06-04", "12:00", 4, 4, 5},
        {"80813033065", 5, "2024-06-05", "13:00", 5, 5, 1}
    };

    int opcao;
    do {
        std::cout << "\n### Menu Principal ###\n";
        std::cout << "1. Mostrar dados\n";
        std::cout << "2. Adicionar dados\n";
        std::cout << "3. Controle\n";
        std::cout << "4. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                int opcaoMostrar;
                std::cout << "\n### Menu Mostrar Dados ###\n";
                std::cout << "1. Mostrar Cidades\n";
                std::cout << "2. Mostrar Especialidades\n";
                std::cout << "3. Mostrar Medicos\n";
                std::cout << "4. Mostrar Pacientes\n";
                std::cout << "5. Mostrar CID\n";
                std::cout << "6. Mostrar Medicamentos\n";
                std::cout << "7. Mostrar Consultas\n";
                std::cout << "Escolha uma opcao: ";
                std::cin >> opcaoMostrar;

                switch (opcaoMostrar) {
                    case 1:
                        mostrarCidades(cidades);
                        break;
                    case 2:
                        mostrarEspecialidades(especialidades);
                        break;
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
                    default:
                        std::cout << "Opcao invalida!\n";
                }
                break;
            case 2:
                int opcaoAdicionar;
                std::cout << "\n### Menu Adicionar Dados ###\n";
                std::cout << "1. Adicionar Cidade\n";
                std::cout << "2. Adicionar Especialidade\n";
                std::cout << "3. Adicionar Medico\n";
                std::cout << "4. Adicionar Paciente\n";
                std::cout << "5. Adicionar CID\n";
                std::cout << "6. Adicionar Medicamento\n";
                std::cout << "7. Excluir Paciente\n";
                std::cout << "8. Agendar consulta\n";
                std::cout << "Escolha uma opcao: ";
                std::cin >> opcaoAdicionar;

                switch (opcaoAdicionar) {
                    case 1:
                        adicionarCidade(cidades);
                        break;
                    case 2:
                        adicionarEspecialidade(especialidades);
                        break;
                    case 3:
                        adicionarMedicoValidado(medicos, especialidades, cidades);
                        break;
                    case 4:
                        adicionarPacienteValidado(pacientes, cidades);
                        break;
                    case 5:
                        adicionarCID(doencas);
                        break;
                    case 6:
                        adicionarMedicamento(medicines);
                        break;
                    case 7:
                        excluirPacientePorNome(pacientes);
                        break;
                    case 8:
                        agendarConsulta(pacientes, medicos, doencas, medicines, consultas, cidades, especialidades);
                        break;
                    default:
                        std::cout << "Opcao invalida!\n";
                }
                break;
            case 3:
                int opcaoControle;
                std::cout << "\n### Menu Controle ###\n";
                std::cout << "1. Sugestao de compras\n";
                std::cout << "2. Valor total arrecadado com consultas\n";
                std::cout << "Escolha uma opcao: ";
                std::cin >> opcaoControle;
            switch (opcaoControle) {
    case 1:
    std::cout << "Sugestoes de compras:\n";
    for (const auto& medicine : medicines) {
        if (medicine.quant_estoque < medicine.estoque_minimo) {
            std::cout << "Codigo: " << medicine.codigo << ", Descricao: " << medicine.descricao
                      << ", Quantidade em estoque: " << medicine.quant_estoque << std::endl;
        }
    }
    break;
  case 2:
    double totalValue = 0.0;
    for (const auto& consulta : consultas) {
        totalValue += 100.00; // Fixed consultation value
    }
    std::cout << "Valor total arrecadado com consultas: R$" << std::fixed << std::setprecision(2) << totalValue << std::endl;
    break;
    
        std::cout << "Opcao invalida!\n";
        break;
}
break;
            case 4:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opcao invalida!\n";
        }
    } while (opcao != 4);

    return 0;
}