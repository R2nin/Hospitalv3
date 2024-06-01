#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Definição das estruturas de dados
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
    int codigoEspecialidade;
    std::string endereco;
    std::string telefone;
    int codigoCidade;
};

struct Pacientes {
    long CPF;
    std::string nome;
    std::string endereco;
    int codigoCidade;
};

struct CID {
    int codigo3;
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
    long CPF;
    int codigoMedico;
    std::string data;
    std::string hora;
    int codigoCID;
    int codigoMedicamento;
    int quantidadeMedicamento;
};

// Funções de leitura de dados
Cidades lerCidade();
Especialidades lerEspecialidade();
Medicos lerMedico();
Pacientes lerPaciente();
CID lerCID();
Medicamentos lerMedicamento();
Consultas lerConsulta();

// Funções para mostrar dados
void mostrarCidades(const std::vector<Cidades>& cidades);
void mostrarEspecialidades(const std::vector<Especialidades>& especialidades);
void mostrarMedicos(const std::vector<Medicos>& medicos);
void mostrarPacientes(const std::vector<Pacientes>& pacientes);
void mostrarCID(const std::vector<CID>& doencas);
void mostrarMedicamentos(const std::vector<Medicamentos>& medicines);
void mostrarConsultas(const std::vector<Consultas>& consultas);

// Funções para adicionar registros
void adicionarCidade(std::vector<Cidades>& cidades);
void adicionarEspecialidade(std::vector<Especialidades>& especialidades);
void adicionarMedico(std::vector<Medicos>& medicos, const std::vector<Especialidades>& especialidades, const std::vector<Cidades>& cidades);
void adicionarPaciente(std::vector<Pacientes>& pacientes, const std::vector<Cidades>& cidades);
void adicionarCID(std::vector<CID>& doencas);
void adicionarMedicamento(std::vector<Medicamentos>& medicines);

// Função para excluir registros de pacientes
void excluirPaciente(std::vector<Pacientes>& pacientes);

// Função para agendar consulta
void agendarConsulta(std::vector<Consultas>& consultas, const std::vector<Pacientes>& pacientes, const std::vector<Medicos>& medicos, const std::vector<CID>& doencas, std::vector<Medicamentos>& medicines);

// Função para consultar dados de medicamento
void consultarMedicamento(const std::vector<Medicamentos>& medicines);

// Função para exibir medicamentos com estoque baixo
void mostrarEstoqueBaixo(const std::vector<Medicamentos>& medicines);

// Função para exibir valor arrecadado com consultas
void valorArrecadadoConsultas(const std::vector<Consultas>& consultas, const std::vector<Medicamentos>& medicines);

// Implementação das funções de leitura de dados
Cidades lerCidade() {
    Cidades cidade;
    std::cout << "Digite o código da cidade: ";
    std::cin >> cidade.codigo;
    std::cin.ignore();
    std::cout << "Digite o nome da cidade: ";
    std::getline(std::cin, cidade.nome);
    std::cout << "Digite o UF da cidade: ";
    std::getline(std::cin, cidade.UF);
    return cidade;
}

Especialidades lerEspecialidade() {
    Especialidades especialidade;
    std::cout << "Digite o código da especialidade: ";
    std::cin >> especialidade.codigo1;
    std::cin.ignore();
    std::cout << "Digite a descrição da especialidade: ";
    std::getline(std::cin, especialidade.descricao);
    return especialidade;
}

Medicos lerMedico() {
    Medicos medico;
    std::cout << "Digite o código do médico: ";
    std::cin >> medico.codigo2;
    std::cin.ignore();
    std::cout << "Digite o nome do médico: ";
    std::getline(std::cin, medico.nome);
    std::cout << "Digite o código da especialidade: ";
    std::cin >> medico.codigoEspecialidade;
    std::cin.ignore();
    std::cout << "Digite o endereço do médico: ";
    std::getline(std::cin, medico.endereco);
    std::cout << "Digite o telefone do médico: ";
    std::getline(std::cin, medico.telefone);
    std::cout << "Digite o código da cidade: ";
    std::cin >> medico.codigoCidade;
    std::cin.ignore();
    return medico;
}

Pacientes lerPaciente() {
    Pacientes paciente;
    std::cout << "Digite o CPF do paciente: ";
    std::cin >> paciente.CPF;
    std::cin.ignore();
    std::cout << "Digite o nome do paciente: ";
    std::getline(std::cin, paciente.nome);
    std::cout << "Digite o endereço do paciente: ";
    std::getline(std::cin, paciente.endereco);
    std::cout << "Digite o código da cidade: ";
    std::cin >> paciente.codigoCidade;
    std::cin.ignore();
    return paciente;
}

CID lerCID() {
    CID cid;
    std::cout << "Digite o código do CID: ";
    std::cin >> cid.codigo3;
    std::cin.ignore();
    std::cout << "Digite a descrição do CID: ";
    std::getline(std::cin, cid.descricao);
    return cid;
}

Medicamentos lerMedicamento() {
    Medicamentos medicamento;
    std::cout << "Digite o código do medicamento: ";
    std::cin >> medicamento.codigo;
    std::cin.ignore();
    std::cout << "Digite a descrição do medicamento: ";
    std::getline(std::cin, medicamento.descricao);
    std::cout << "Digite a quantidade em estoque: ";
    std::cin >> medicamento.quant_estoque;
    std::cout << "Digite o estoque mínimo: ";
    std::cin >> medicamento.estoque_minimo;
    std::cout << "Digite o estoque máximo: ";
    std::cin >> medicamento.estoque_maximo;
    std::cout << "Digite o preço unitário: ";
    std::cin >> medicamento.preco_unitario;
    std::cin.ignore();
    return medicamento;
}

Consultas lerConsulta() {
    Consultas consulta;
    std::cout << "Digite o CPF do paciente: ";
    std::cin >> consulta.CPF;
    std::cin.ignore();
    std::cout << "Digite o código do médico: ";
    std::cin >> consulta.codigoMedico;
    std::cin.ignore();
    std::cout << "Digite a data da consulta (YYYY-MM-DD): ";
    std::getline(std::cin, consulta.data);
    std::cout << "Digite a hora da consulta (HH:MM): ";
    std::getline(std::cin, consulta.hora);
    std::cout << "Digite o código do CID: ";
    std::cin >> consulta.codigoCID;
    std::cin.ignore();
    std::cout << "Digite o código do medicamento: ";
    std::cin >> consulta.codigoMedicamento;
    std::cin.ignore();
    std::cout << "Digite a quantidade do medicamento: ";
    std::cin >> consulta.quantidadeMedicamento;
    std::cin.ignore();
    return consulta;
}

// Implementação das funções para mostrar dados
void mostrarCidades(const std::vector<Cidades>& cidades) {
    for (const auto& cidade : cidades) {
        std::cout << "Código: " << cidade.codigo << ", Nome: " << cidade.nome << ", UF: " << cidade.UF << '\n';
    }
}

void mostrarEspecialidades(const std::vector<Especialidades>& especialidades) {
    for (const auto& especialidade : especialidades) {
        std::cout << "Código: " << especialidade.codigo1 << ", Descrição: " << especialidade.descricao << '\n';
    }
}

void mostrarMedicos(const std::vector<Medicos>& medicos) {
    for (const auto& medico : medicos) {
        std::cout << "Código: " << medico.codigo2 << ", Nome: " << medico.nome
                  << ", Código Especialidade: " << medico.codigoEspecialidade
                  << ", Endereço: " << medico.endereco
                  << ", Telefone: " << medico.telefone
                  << ", Código Cidade: " << medico.codigoCidade << '\n';
    }
}

void mostrarPacientes(const std::vector<Pacientes>& pacientes) {
    for (const auto& paciente : pacientes) {
        std::cout << "CPF: " << paciente.CPF << ", Nome: " << paciente.nome
                  << ", Endereço: " << paciente.endereco
                  << ", Código Cidade: " << paciente.codigoCidade << '\n';
    }
}

void mostrarCID(const std::vector<CID>& doencas) {
    for (const auto& cid : doencas) {
        std::cout << "Código: " << cid.codigo3 << ", Descrição: " << cid.descricao << '\n';
    }
}

void mostrarMedicamentos(const std::vector<Medicamentos>& medicines) {
    for (const auto& medicine : medicines) {
        std::cout << "Código: " << medicine.codigo << ", Descrição: " << medicine.descricao
                  << ", Quantidade em Estoque: " << medicine.quant_estoque
                  << ", Estoque Mínimo: " << medicine.estoque_minimo
                  << ", Estoque Máximo: " << medicine.estoque_maximo
                  << ", Preço Unitário: " << medicine.preco_unitario << '\n';
    }
}

void mostrarConsultas(const std::vector<Consultas>& consultas) {
    for (const auto& consulta : consultas) {
        std::cout << "CPF: " << consulta.CPF << ", Código Médico: " << consulta.codigoMedico
                  << ", Data: " << consulta.data << ", Hora: " << consulta.hora
                  << ", Código CID: " << consulta.codigoCID
                  << ", Código Medicamento: " << consulta.codigoMedicamento
                  << ", Quantidade Medicamento: " << consulta.quantidadeMedicamento << '\n';
    }
}

// Implementação das funções para adicionar registros
void adicionarCidade(std::vector<Cidades>& cidades) {
    Cidades cidade = lerCidade();
    auto it = std::find_if(cidades.begin(), cidades.end(), [&](const Cidades& c) { return c.codigo == cidade.codigo; });
    if (it != cidades.end()) {
        std::cout << "Cidade com o código " << cidade.codigo << " já existe.\n";
    } else {
        cidades.push_back(cidade);
        std::cout << "Cidade adicionada com sucesso!\n";
    }
}

void adicionarEspecialidade(std::vector<Especialidades>& especialidades) {
    Especialidades especialidade = lerEspecialidade();
    auto it = std::find_if(especialidades.begin(), especialidades.end(), [&](const Especialidades& e) { return e.codigo1 == especialidade.codigo1; });
    if (it != especialidades.end()) {
        std::cout << "Especialidade com o código " << especialidade.codigo1 << " já existe.\n";
    } else {
        especialidades.push_back(especialidade);
        std::cout << "Especialidade adicionada com sucesso!\n";
    }
}

void adicionarMedico(std::vector<Medicos>& medicos, const std::vector<Especialidades>& especialidades, const std::vector<Cidades>& cidades) {
    Medicos medico = lerMedico();
    auto it = std::find_if(medicos.begin(), medicos.end(), [&](const Medicos& m) { return m.codigo2 == medico.codigo2; });
    if (it != medicos.end()) {
        std::cout << "Médico com o código " << medico.codigo2 << " já existe.\n";
        return;
    }

    auto itEspecialidade = std::find_if(especialidades.begin(), especialidades.end(), [&](const Especialidades& e) { return e.codigo1 == medico.codigoEspecialidade; });
    if (itEspecialidade == especialidades.end()) {
        std::cout << "Especialidade com o código " << medico.codigoEspecialidade << " não encontrada.\n";
        return;
    }
    std::cout << "Descrição da especialidade: " << itEspecialidade->descricao << '\n';

    auto itCidade = std::find_if(cidades.begin(), cidades.end(), [&](const Cidades& c) { return c.codigo == medico.codigoCidade; });
    if (itCidade == cidades.end()) {
        std::cout << "Cidade com o código " << medico.codigoCidade << " não encontrada.\n";
        return;
    }
    std::cout << "Nome da cidade: " << itCidade->nome << ", UF: " << itCidade->UF << '\n';

    medicos.push_back(medico);
    std::cout << "Médico adicionado com sucesso!\n";
}

void adicionarPaciente(std::vector<Pacientes>& pacientes, const std::vector<Cidades>& cidades) {
    Pacientes paciente = lerPaciente();
    auto it = std::find_if(pacientes.begin(), pacientes.end(), [&](const Pacientes& p) { return p.CPF == paciente.CPF; });
    if (it != pacientes.end()) {
        std::cout << "Paciente com o CPF " << paciente.CPF << " já existe.\n";
        return;
    }

    auto itCidade = std::find_if(cidades.begin(), cidades.end(), [&](const Cidades& c) { return c.codigo == paciente.codigoCidade; });
    if (itCidade == cidades.end()) {
        std::cout << "Cidade com o código " << paciente.codigoCidade << " não encontrada.\n";
        return;
    }
    std::cout << "Nome da cidade: " << itCidade->nome << ", UF: " << itCidade->UF << '\n';

    pacientes.push_back(paciente);
    std::cout << "Paciente adicionado com sucesso!\n";
}

void adicionarCID(std::vector<CID>& doencas) {
    CID cid = lerCID();
    auto it = std::find_if(doencas.begin(), doencas.end(), [&](const CID& c) { return c.codigo3 == cid.codigo3; });
    if (it != doencas.end()) {
        std::cout << "CID com o código " << cid.codigo3 << " já existe.\n";
    } else {
        doencas.push_back(cid);
        std::cout << "CID adicionado com sucesso!\n";
    }
}

void adicionarMedicamento(std::vector<Medicamentos>& medicines) {
    Medicamentos medicamento = lerMedicamento();
    auto it = std::find_if(medicines.begin(), medicines.end(), [&](const Medicamentos& m) { return m.codigo == medicamento.codigo; });
    if (it != medicines.end()) {
        std::cout << "Medicamento com o código " << medicamento.codigo << " já existe.\n";
    } else {
        medicines.push_back(medicamento);
        std::cout << "Medicamento adicionado com sucesso!\n";
    }
}

// Implementação da função para excluir registros de pacientes
void excluirPaciente(std::vector<Pacientes>& pacientes) {
    long cpf;
    std::cout << "Digite o CPF do paciente a ser excluído: ";
    std::cin >> cpf;
    auto it = std::find_if(pacientes.begin(), pacientes.end(), [&](const Pacientes& p) { return p.CPF == cpf; });
    if (it != pacientes.end()) {
        pacientes.erase(it);
        std::cout << "Paciente excluído com sucesso!\n";
    } else {
        std::cout << "Paciente com o CPF " << cpf << " não encontrado.\n";
    }
}

// Implementação da função para agendar consulta
void agendarConsulta(std::vector<Consultas>& consultas, const std::vector<Pacientes>& pacientes, const std::vector<Medicos>& medicos, const std::vector<CID>& doencas, std::vector<Medicamentos>& medicines) {
    Consultas consulta = lerConsulta();

    auto itPaciente = std::find_if(pacientes.begin(), pacientes.end(), [&](const Pacientes& p) { return p.CPF == consulta.CPF; });
    if (itPaciente == pacientes.end()) {
        std::cout << "Paciente com o CPF " << consulta.CPF << " não encontrado.\n";
        return;
    }
    std::cout << "Nome do paciente: " << itPaciente->nome << '\n';

    auto itCidade = std::find_if(pacientes.begin(), pacientes.end(), [&](const Pacientes& p) { return p.CPF == consulta.CPF; });
    if (itCidade != pacientes.end()) {
        std::cout << "Cidade do paciente: " << itCidade->nome << ", UF: " << itCidade->UF << '\n';
    }

    auto itMedico = std::find_if(medicos.begin(), medicos.end(), [&](const Medicos& m) { return m.codigo2 == consulta.codigoMedico; });
    if (itMedico == medicos.end()) {
        std::cout << "Médico com o código " << consulta.codigoMedico << " não encontrado.\n";
        return;
    }
    std::cout << "Nome do médico: " << itMedico->nome << '\n';

    auto itEspecialidade = std::find_if(especialidades.begin(), especialidades.end(), [&](const Especialidades& e) { return e.codigo1 == itMedico->codigoEspecialidade; });
    if (itEspecialidade != especialidades.end()) {
        std::cout << "Descrição da especialidade: " << itEspecialidade->descricao << '\n';
    }

    auto itCID = std::find_if(doencas.begin(), doencas.end(), [&](const CID& c) { return c.codigo3 == consulta.codigoCID; });
    if (itCID == doencas.end()) {
        std::cout << "CID com o código " << consulta.codigoCID << " não encontrado.\n";
        return;
    }
    std::cout << "Descrição do CID: " << itCID->descricao << '\n';

    auto itMedicamento = std::find_if(medicines.begin(), medicines.end(), [&](const Medicamentos& m) { return m.codigo == consulta.codigoMedicamento; });
    if (itMedicamento == medicines.end()) {
        std::cout << "Medicamento com o código " << consulta.codigoMedicamento << " não encontrado.\n";
        return;
    }
    std::cout << "Descrição do medicamento: " << itMedicamento->descricao << '\n';

    if (consulta.quantidadeMedicamento > itMedicamento->quant_estoque) {
        std::cout << "Quantidade em estoque insuficiente para atender a consulta.\n";
        return;
    }
    itMedicamento->quant_estoque -= consulta.quantidadeMedicamento;

    consultas.push_back(consulta);
    std::cout << "Consulta agendada com sucesso!\n";
}

// Implementação da função para consultar dados de medicamento
void consultarMedicamento(const std::vector<Medicamentos>& medicines) {
    int codigo;
    std::cout << "Digite o código do medicamento: ";
    std::cin >> codigo;
    auto it = std::find_if(medicines.begin(), medicines.end(), [&](const Medicamentos& m) { return m.codigo == codigo; });
    if (it != medicines.end()) {
        std::cout << "Código: " << it->codigo << ", Descrição: " << it->descricao
                  << ", Quantidade em Estoque: " << it->quant_estoque
                  << ", Estoque Mínimo: " << it->estoque_minimo
                  << ", Estoque Máximo: " << it->estoque_maximo
                  << ", Preço Unitário: " << it->preco_unitario << '\n';
        double valorTotal = it->quant_estoque * it->preco_unitario;
        std::cout << "Valor total em estoque: " << valorTotal << '\n';
    } else {
        std::cout << "Medicamento com o código " << codigo << " não encontrado.\n";
    }
}

// Implementação da função para exibir medicamentos com estoque baixo
void mostrarEstoqueBaixo(const std::vector<Medicamentos>& medicines) {
    double valorTotalCompra = 0.0;
    for (const auto& medicine : medicines) {
        if (medicine.quant_estoque < medicine.estoque_minimo) {
            int qtdeComprar = medicine.estoque_maximo - medicine.quant_estoque;
            double valorCompra = qtdeComprar * medicine.preco_unitario;
            valorTotalCompra += valorCompra;
            std::cout << "Código: " << medicine.codigo << ", Descrição: " << medicine.descricao
                      << ", Quantidade em Estoque: " << medicine.quant_estoque
                      << ", Estoque Máximo: " << medicine.estoque_maximo
                      << ", Quantidade a ser Comprada: " << qtdeComprar
                      << ", Valor da Compra: " << valorCompra << '\n';
        }
    }
    std::cout << "Valor total a ser comprado: " << valorTotalCompra << '\n';
}

// Implementação da função para exibir valor arrecadado com consultas
void valorArrecadadoConsultas(const std::vector<Consultas>& consultas, const std::vector<Medicamentos>& medicines) {
    double valorTotal = 0.0;
    for (const auto& consulta : consultas) {
        double valorConsulta = 100.0;
        auto itMedicamento = std::find_if(medicines.begin(), medicines.end(), [&](const Medicamentos& m) { return m.codigo == consulta.codigoMedicamento; });
        if (itMedicamento != medicines.end()) {
            double valorMedicamento = consulta.quantidadeMedicamento * itMedicamento->preco_unitario;
            valorTotal += valorConsulta + valorMedicamento;
        } else {
            valorTotal += valorConsulta;
        }
    }
    std::cout << "Valor total arrecadado com consultas: " << valorTotal << '\n';
}

// Função principal
int main() {
    std::vector<Cidades> cidades;
    std::vector<Especialidades> especialidades;
    std::vector<Medicos> medicos;
    std::vector<Pacientes> pacientes;
    std::vector<CID> doencas;
    std::vector<Medicamentos> medicines;
    std::vector<Consultas> consultas;

    int opcao;
    do {
        std::cout << "Menu de Opções:\n";
        std::cout << "1. Adicionar Cidade\n";
        std::cout << "2. Adicionar Especialidade\n";
        std::cout << "3. Adicionar Médico\n";
        std::cout << "4. Adicionar Paciente\n";
        std::cout << "5. Adicionar CID\n";
        std::cout << "6. Adicionar Medicamento\n";
        std::cout << "7. Excluir Paciente\n";
        std::cout << "8. Agendar Consulta\n";
        std::cout << "9. Consultar Medicamento\n";
        std::cout << "10. Mostrar Medicamentos com Estoque Baixo\n";
        std::cout << "11. Valor Arrecadado com Consultas\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarCidade(cidades);
                break;
            case 2:
                adicionarEspecialidade(especialidades);
                break;
            case 3:
                adicionarMedico(medicos, especialidades, cidades);
                break;
            case 4:
                adicionarPaciente(pacientes, cidades);
                break;
            case 5:
                adicionarCID(doencas);
                break;
            case 6:
                adicionarMedicamento(medicines);
                break;
            case 7:
                excluirPaciente(pacientes);
                break;
            case 8:
                agendarConsulta(consultas, pacientes, medicos, doencas, medicines);
                break;
            case 9:
                consultarMedicamento(medicines);
                break;
            case 10:
                mostrarEstoqueBaixo(medicines);
                break;
            case 11:
                valorArrecadadoConsultas(consultas, medicines);
                break;
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}
