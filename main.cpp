#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h>
#include "classes.h"
#include "base_nomes.h"
#include "csv_func.h"

#define NUM_AREAS_DE_CONHECIMENTO 10
#define SIZE_AREAS_DE_CONHECIMENTO 3

#define NUM_LOCAL_NOMES 100
#define SIZE_LOCAL_NOMES 5

#define NUM_PROFESSORES 10000
#define NUM_ALUNOS 10000
#define SIZE_NOMES 20
#define SIZE_SOBRENOMES 20
#define SIZE_PROFESSOR_SITE 4
#define SIZE_PROFESSOR_TITULO 5
#define SIZE_PROFESSOR_CLASSE 4

#define NUM_CURSOS 400
#define SIZE_CURSOS_EXATAS 3
#define SIZE_CURSOS_HUMANAS 3
#define SIZE_CURSOS_MEDICAS 3

#define NUM_DISCIPLINAS 2000
#define SIZE_DISCIPLINAS_CODIGOS 20
#define SIZE_DISCIPLINAS_EMENTA 3
#define SIZE_DISCIPLINAS_BIBLIOGRAFIA 3

#define SIZE_DISCIPLINAS_OBRIGATORIAS_EXATAS 3
#define SIZE_DISCIPLINAS_OPTATIVAS_EXATAS 3
#define SIZE_DISCIPLINAS_ELETIVAS_EXATAS 3

#define SIZE_DISCIPLINAS_OBRIGATORIAS_HUMANAS 3
#define SIZE_DISCIPLINAS_OPTATIVAS_HUMANAS 3
#define SIZE_DISCIPLINAS_ELETIVAS_HUMANAS 3

#define SIZE_DISCIPLINAS_OBRIGATORIAS_MEDICAS 3
#define SIZE_DISCIPLINAS_OPTATIVAS_MEDICAS 3
#define SIZE_DISCIPLINAS_ELETIVAS_MEDICAS 3

#define NUM_REL_PRE_REQUISITOS 400

#define NUM_REL_CURSO_DISCIPLINA 400

#define NUM_TURMAS 500

#define NUM_REL_TURMA_ALUNOS 700000

#define NUM_EXTENSAO 10000
#define SIZE_EXTENSAO 4

#define NUM_TRABALHO 3000
#define SIZE_NOME_TRABAHO 3


using namespace std;

vector <int> geraCodigosAleatorios ()
{
    vector <int> codigos;
    for (int i=0; i<10000; i ++)
    {
        codigos.push_back(i);
    }

    return codigos;
}

int getCodigo (vector <int> &codigos)
{
    int rndIndex = rand() % codigos.size();
    int rndValue = codigos[rndIndex];
    codigos.erase(codigos.begin() + rndIndex);

    return rndValue;
}

vector <Area_de_Conhecimento>  geraAreas ()
{
    vector <Area_de_Conhecimento> areas;
    vector <int> codigos = geraCodigosAleatorios ();
    string nm_Area;
    int cd_Area;

    for (int i=0; i< NUM_AREAS_DE_CONHECIMENTO; i++)
    {
        cd_Area = getCodigo (codigos);
        nm_Area = AREA_DE_CONHECIMENTO [rand() % SIZE_AREAS_DE_CONHECIMENTO];

        Area_de_Conhecimento area (cd_Area, nm_Area);
        areas.push_back(area);
    }

    return areas;
}

vector <Local> geraLocais ()
{
    vector <Local> locais;
    vector <int> codigos = geraCodigosAleatorios ();
    int nu_Telefone;
    string nm_Local;
    int cd_Local;

    for (int i=0; i<NUM_LOCAL_NOMES; i++)
    {
        cd_Local = getCodigo (codigos);
        nu_Telefone = 70000000 + rand () % 29999999;
        nm_Local = LOCAL_NOMES [rand () % SIZE_LOCAL_NOMES];

        Local local (cd_Local, nu_Telefone, nm_Local);
        locais.push_back(local);
    }

    return locais;
}

Pessoa getPessoa (vector <Pessoa> &pessoas)
{
    int rndIndex = rand() % pessoas.size();
    Pessoa rndValue = pessoas[rndIndex];
    pessoas.erase(pessoas.begin() + rndIndex);

    return rndValue;
}

vector <Pessoa> geraPessoas (int numPessoas)
{
    vector <Pessoa> pessoas;
    vector <int> codigos = geraCodigosAleatorios ();
    string nm_Pessoa;
    int cd_Pessoa;

    for (int i=0; i<numPessoas; i++)
    {
        cd_Pessoa = getCodigo (codigos);
        nm_Pessoa = NOMES [rand() % SIZE_NOMES] + " " + SOBRENOMES [rand() % SIZE_SOBRENOMES];

        Pessoa pessoa (cd_Pessoa, nm_Pessoa);
        pessoas.push_back (pessoa);
    }

    return pessoas;
}

vector <Professor> geraProfessores (vector <Local> locais)
{
    vector <Professor> professores;
    vector <Pessoa> pessoas = geraPessoas (NUM_PROFESSORES);
    vector <int> codigos = geraCodigosAleatorios ();
    string nm_Site;
    string nm_Email;
    int nu_SIAPE;
    string nm_Titulo;
    string nm_Classe;
    int cd_Professor;

    for (int i=0; i<NUM_PROFESSORES; i++)
    {
        cd_Professor = getCodigo (codigos);
        Pessoa cd_Pessoa = getPessoa (pessoas);
        Local cd_Local = locais [rand() % locais.size()];
        size_t pos = cd_Pessoa.nm_Pessoa.find(" ");
        nm_Site = PROFESSOR_SITE [rand() % SIZE_PROFESSOR_SITE] + cd_Pessoa.nm_Pessoa.substr(0,pos);
        nm_Email = cd_Pessoa.nm_Pessoa.substr(0,pos) + "@gmail.com";
        nu_SIAPE = 1000 + rand () % 8999;
        nm_Titulo = PROFESSOR_TITULO [rand() % SIZE_PROFESSOR_TITULO];
        nm_Classe = PROFESSOR_CLASSE [rand() % SIZE_PROFESSOR_CLASSE];

        Professor professor (cd_Professor, cd_Pessoa, cd_Local, nm_Site, nm_Email, nu_SIAPE, nm_Titulo, nm_Classe);
        professores.push_back (professor);
    }

    return professores;
}

vector <Curso> geraCursos (vector<Area_de_Conhecimento> areas, vector<Professor> professores)
{
    vector <Curso> cursos;
    vector <int> codigos = geraCodigosAleatorios ();
    string nm_Curso;
    int cd_Curso;

    for (int i=0; i<NUM_CURSOS; i++)
    {
        cd_Curso = getCodigo(codigos);
        Area_de_Conhecimento cd_Area = areas[rand() % areas.size ()];
        Professor cd_Coordenador = professores[rand() % professores.size ()];

        if (cd_Area.nm_Area == "Exatas")
            nm_Curso = CURSOS_EXATAS [rand() % SIZE_CURSOS_EXATAS];

        if (cd_Area.nm_Area == "Humanas")
            nm_Curso = CURSOS_HUMANAS [rand() % SIZE_CURSOS_HUMANAS];

        if (cd_Area.nm_Area == "Medicas")
            nm_Curso = CURSOS_MEDICAS [rand() % SIZE_CURSOS_MEDICAS];

        Curso curso (cd_Curso, cd_Area, cd_Coordenador, nm_Curso);
        cursos.push_back(curso);
    }

    return cursos;
}

string getNomeDisciplina (int tipoCurso, int tipoDisciplina) //tipoCurso: Medicas, Humanas ou Exatas; tipoDisciplina: Obrigatoria, Eletiva ou Optativa
{

    if (tipoCurso == 0)
    {
        if (tipoDisciplina == 0)
            return DISCIPLINAS_OBRIGATORIAS_EXATAS [rand () % SIZE_DISCIPLINAS_OBRIGATORIAS_EXATAS];

        if (tipoDisciplina == 1)
            return DISCIPLINAS_OPTATIVAS_EXATAS [rand () % SIZE_DISCIPLINAS_OPTATIVAS_EXATAS];

        if (tipoDisciplina == 2)
            return DISCIPLINAS_ELETIVAS_EXATAS [rand () % SIZE_DISCIPLINAS_ELETIVAS_EXATAS];
    }

    if (tipoCurso == 1)
    {
        if (tipoDisciplina == 0)
            return DISCIPLINAS_OBRIGATORIAS_HUMANAS [rand () % SIZE_DISCIPLINAS_OBRIGATORIAS_HUMANAS];

        if (tipoDisciplina == 1)
            return DISCIPLINAS_OPTATIVAS_HUMANAS [rand () % SIZE_DISCIPLINAS_OPTATIVAS_HUMANAS];

        if (tipoDisciplina == 2)
            return DISCIPLINAS_ELETIVAS_HUMANAS [rand () % SIZE_DISCIPLINAS_ELETIVAS_HUMANAS];
    }

    if (tipoCurso == 2)
    {
        if (tipoDisciplina == 0)
            return DISCIPLINAS_OBRIGATORIAS_MEDICAS [rand () % SIZE_DISCIPLINAS_OBRIGATORIAS_MEDICAS];

        if (tipoDisciplina == 1)
            return DISCIPLINAS_OPTATIVAS_MEDICAS [rand () % SIZE_DISCIPLINAS_OPTATIVAS_MEDICAS];

        if (tipoDisciplina == 2)
            return DISCIPLINAS_ELETIVAS_MEDICAS [rand () % SIZE_DISCIPLINAS_ELETIVAS_MEDICAS];
    }
}

vector <Disciplina> geraDisciplina (int tipoCurso, int tipoDisciplina) //tipoCurso: Exatas, Humanas ou Medicas; tipoDisciplina: Obrigatoria, Optativas ou Eletivas
{
    vector <Disciplina> disciplinas;
    vector <int> codigos = geraCodigosAleatorios ();
    string cd_Codigo;
    int hh_Carga_Horaria;
    string nm_Ementa;
    string nm_Bibliografia;
    string nm_Disciplina;
    int cd_Disciplina;

    for (int i=0; i<NUM_DISCIPLINAS; i++)
    {
        cd_Disciplina = getCodigo (codigos);
        cd_Codigo = DISCIPLINAS_CODIGOS [rand() % SIZE_DISCIPLINAS_CODIGOS];
        hh_Carga_Horaria = 1 + rand () % 5;
        nm_Ementa = DISCIPLINAS_EMENTA [rand () % SIZE_DISCIPLINAS_EMENTA];
        nm_Bibliografia = DISCIPLINAS_BIBLIOGRAFIA [rand() % SIZE_DISCIPLINAS_BIBLIOGRAFIA];
        nm_Disciplina = getNomeDisciplina (tipoCurso, tipoDisciplina);

        Disciplina disciplina (cd_Disciplina, cd_Codigo, hh_Carga_Horaria, nm_Ementa, nm_Bibliografia, nm_Disciplina);
        disciplinas.push_back (disciplina);
    }

    return disciplinas;
}

Disciplina getDisciplina (vector <Disciplina> &disciplinas)
{
    int rndIndex = rand() % disciplinas.size();
    Disciplina rndValue = disciplinas[rndIndex];
    disciplinas.erase(disciplinas.begin() + rndIndex);

    return rndValue;
}

vector <Rel_Pre_Requisito> geraPreRequisitos (vector <Disciplina> disciplinas)
{
    vector <Rel_Pre_Requisito> preRequisitos;


    for (int i=0; i< NUM_REL_PRE_REQUISITOS; i++)
    {
        vector <Disciplina> auxDisciplina = disciplinas;
        Disciplina cd_Disciplina = getDisciplina (auxDisciplina);
        Disciplina cd_Pre_Requisito = getDisciplina (auxDisciplina);

        Rel_Pre_Requisito preRequisito (cd_Disciplina, cd_Pre_Requisito);
        preRequisitos.push_back (preRequisito);
    }

    return preRequisitos;
}

vector <Rel_Curso_Disciplina> geraCursoDisciplina (vector <Curso> cursos, vector <Disciplina> disciplinas, int tipoDisciplina)
{
    vector <Rel_Curso_Disciplina> cursoDisciplinas;
    string nm_Obrigatoriedade;

    for (int i=0; i<NUM_REL_CURSO_DISCIPLINA; i++)
    {
        Curso cd_Curso = cursos [rand() % cursos.size()];
        Disciplina cd_Disciplina = disciplinas [rand() % disciplinas.size()];

        nm_Obrigatoriedade = OBRIGATORIEDADE [tipoDisciplina];

        Rel_Curso_Disciplina cursoDisciplina (cd_Curso, cd_Disciplina, nm_Obrigatoriedade);
        cursoDisciplinas.push_back(cursoDisciplina);
    }

    return cursoDisciplinas;
}

vector <Aluno> geraAluno (vector<Professor> professores, vector<Curso> cursos)
{
    vector <Aluno> alunos;
    vector <Pessoa> pessoas = geraPessoas (NUM_ALUNOS);
    vector <int> codigos = geraCodigosAleatorios ();
    int cd_Aluno;

    for (int i=0; i<NUM_ALUNOS; i++)
    {
        cd_Aluno = getCodigo (codigos);
        Pessoa cd_Pessoa = getPessoa (pessoas);
        Professor cd_Orientador = professores [rand() % professores.size()];
        Curso cd_Curso = cursos [rand ()% cursos.size()];

        Aluno aluno (cd_Aluno, cd_Pessoa, cd_Orientador, cd_Curso);
        alunos.push_back (aluno);

    }

    return alunos;

}

vector <Turma> geraTurmas (vector<Disciplina> disciplinas, vector<Local> locais, vector<Professor> professores)
{
    vector<Turma> turmas;
    vector<int> codigos = geraCodigosAleatorios ();
    int hh_Horario;
    int nu_Vagas;
    int nu_Turma;
    int cd_Turma;

    for (int i=0; i<NUM_TURMAS; i++)
    {
        cd_Turma = getCodigo(codigos);
        Disciplina cd_Disciplina = disciplinas [rand() % disciplinas.size()];
        Local cd_Local = locais [rand() % locais.size()];
        Professor cd_Professor = professores [rand () % professores.size()];
        hh_Horario = 1 + rand() % 6;
        nu_Vagas = 10 + rand() % 40;
        nu_Turma = rand () % 3;

        Turma turma  (cd_Turma, cd_Disciplina, cd_Local, cd_Professor, hh_Horario, nu_Vagas, nu_Turma);
        turmas.push_back (turma);
    }

    return turmas;
}

vector <Rel_Turma_Aluno> geraTurmaAlunos (vector<Turma> turmas, vector<Aluno> alunos)
{
    vector<Rel_Turma_Aluno> turmaAlunos;
    int nu_Nota;

    for (int i = 0; i< NUM_REL_TURMA_ALUNOS; i++)
    {
        Turma cd_Turma = turmas[rand() % turmas.size()];
        Aluno cd_Aluno = alunos[rand() % alunos.size()];
        nu_Nota = rand() % 10;

        Rel_Turma_Aluno turmaAluno (cd_Turma, cd_Aluno, nu_Nota);
        turmaAlunos.push_back (turmaAluno);
    }

    return turmaAlunos;
}

vector<Extensao> geraExtensoes (vector<Aluno> alunos, vector<Professor> professores)
{
    vector<Extensao> extensoes;
    vector <int> codigos = geraCodigosAleatorios ();
    string nm_Extensao;
    int cd_Extensao;

    for (int i = 0; i< NUM_EXTENSAO; i++)
    {
        cd_Extensao = getCodigo(codigos);
        Aluno cd_Aluno = alunos[rand() % alunos.size()];
        Professor cd_Orientador = professores[rand() % professores.size()];

        nm_Extensao = EXTENSAO [rand() % SIZE_EXTENSAO];

        Extensao extensao (cd_Extensao, cd_Aluno, cd_Orientador, nm_Extensao);
        extensoes.push_back (extensao);
    }

    return extensoes;
}

vector<Trabalho> geraTrabalhos (vector<Extensao> extensoes)
{
    vector <Trabalho> trabalhos;
    vector <int> codigos = geraCodigosAleatorios ();
    int nu_Nota;
    string nm_Trabalho;
    int cd_Trabalho;


    for (int i=0; i<NUM_TRABALHO; i++)
    {
        cd_Trabalho = getCodigo (codigos);
        Extensao cd_Extensao = extensoes[rand() % extensoes.size()];
        nu_Nota = rand() % 10;
        nm_Trabalho = NOME_TRABALHO [ rand () % SIZE_NOME_TRABAHO];

        Trabalho trabalho (cd_Trabalho, cd_Extensao, nu_Nota, nm_Trabalho);
        trabalhos.push_back (trabalho);

    }

    return trabalhos;
}

int main()
{
     // Start a seed...
     srand (time(NULL));

    vector <Area_de_Conhecimento> areas = geraAreas();

    vector <Local> locais = geraLocais();

    vector <Professor> professores = geraProfessores(locais);

    vector <Curso> cursos = geraCursos (areas, professores);

    vector <Disciplina> disciplinas_obrigatorias_exatas = geraDisciplina(0,0);
    vector <Disciplina> disciplinas_optativas_exatas = geraDisciplina(0,1);
    vector <Disciplina> disciplinas_eletivas_exatas = geraDisciplina(0,2);
    vector <Disciplina> disciplinas_exatas = disciplinas_obrigatorias_exatas;
    disciplinas_exatas.insert (disciplinas_exatas.end(), disciplinas_optativas_exatas.begin(), disciplinas_optativas_exatas.end());
    disciplinas_exatas.insert (disciplinas_exatas.end(), disciplinas_eletivas_exatas.begin(), disciplinas_eletivas_exatas.end());

    vector <Disciplina> disciplinas_obrigatorias_humanas = geraDisciplina(1,0);
    vector <Disciplina> disciplinas_optativas_humanas = geraDisciplina(1,1);
    vector <Disciplina> disciplinas_eletivas_humanas = geraDisciplina(1,2);
    vector <Disciplina> disciplinas_humanas = disciplinas_obrigatorias_humanas;
    disciplinas_humanas.insert (disciplinas_humanas.end(), disciplinas_optativas_humanas.begin(), disciplinas_optativas_humanas.end());
    disciplinas_humanas.insert (disciplinas_humanas.end(), disciplinas_eletivas_humanas.begin(), disciplinas_eletivas_humanas.end());

    vector <Disciplina> disciplinas_obrigatorias_medicas = geraDisciplina(2,0);
    vector <Disciplina> disciplinas_optativas_medicas = geraDisciplina(2,1);
    vector <Disciplina> disciplinas_eletivas_medicas = geraDisciplina(2,2);
    vector <Disciplina> disciplinas_medicas = disciplinas_obrigatorias_medicas;
    disciplinas_medicas.insert (disciplinas_medicas.end(), disciplinas_optativas_medicas.begin(), disciplinas_optativas_medicas.end());
    disciplinas_medicas.insert (disciplinas_medicas.end(), disciplinas_eletivas_medicas.begin(), disciplinas_eletivas_medicas.end());

    vector <Rel_Pre_Requisito> preRequisito_exatas = geraPreRequisitos (disciplinas_exatas);
    vector <Rel_Pre_Requisito> preRequisito_humanas = geraPreRequisitos (disciplinas_humanas);
    vector <Rel_Pre_Requisito> preRequisito_medicas = geraPreRequisitos (disciplinas_medicas);
    vector <Rel_Pre_Requisito> preRequisitos = preRequisito_exatas;
    preRequisitos.insert (preRequisitos.end(), preRequisito_humanas.begin(), preRequisito_humanas.end());
    preRequisitos.insert (preRequisitos.end(), preRequisito_medicas.begin(), preRequisito_medicas.end());

    vector <Disciplina> disciplinas_obrigatorias = disciplinas_obrigatorias_exatas;
    disciplinas_obrigatorias.insert (disciplinas_obrigatorias.end(), disciplinas_obrigatorias_humanas.begin(), disciplinas_obrigatorias_humanas.end());
    disciplinas_obrigatorias.insert (disciplinas_obrigatorias.end(), disciplinas_obrigatorias_medicas.begin(), disciplinas_obrigatorias_medicas.end());

    vector <Disciplina> disciplinas_optativas = disciplinas_optativas_exatas;
    disciplinas_optativas.insert (disciplinas_optativas.end(), disciplinas_optativas_humanas.begin(), disciplinas_optativas_humanas.end());
    disciplinas_optativas.insert (disciplinas_optativas.end(), disciplinas_optativas_medicas.begin(), disciplinas_optativas_medicas.end());

    vector <Disciplina> disciplinas_eletivas = disciplinas_eletivas_exatas;
    disciplinas_eletivas.insert (disciplinas_eletivas.end(), disciplinas_eletivas_humanas.begin(), disciplinas_eletivas_humanas.end());
    disciplinas_eletivas.insert (disciplinas_eletivas.end(), disciplinas_eletivas_medicas.begin(), disciplinas_eletivas_medicas.end());


    vector<Rel_Curso_Disciplina> cursoDisciplinaObrigatorias = geraCursoDisciplina (cursos, disciplinas_obrigatorias, 0);
    vector<Rel_Curso_Disciplina> cursoDisciplinaOptativas = geraCursoDisciplina (cursos, disciplinas_optativas, 1);
    vector<Rel_Curso_Disciplina> cursoDisciplinaEletivas = geraCursoDisciplina (cursos, disciplinas_eletivas, 2);
    vector <Rel_Curso_Disciplina> cursoDisciplinas = cursoDisciplinaObrigatorias;
    cursoDisciplinas.insert (cursoDisciplinas.end(), cursoDisciplinaOptativas.begin(), cursoDisciplinaOptativas.end());
    cursoDisciplinas.insert (cursoDisciplinas.end(), cursoDisciplinaEletivas.begin(), cursoDisciplinaEletivas.end());


    vector <Aluno> alunos = geraAluno (professores,cursos);

    vector <Disciplina> disciplinas = disciplinas_optativas;
    disciplinas.insert (disciplinas.end(), disciplinas_optativas.begin(), disciplinas_optativas.end());
    disciplinas.insert (disciplinas.end(), disciplinas_eletivas.begin(), disciplinas_eletivas.end());

    vector <Turma> turmas = geraTurmas(disciplinas, locais, professores);

    vector <Rel_Turma_Aluno> turmaAlunos = geraTurmaAlunos (turmas, alunos);

    vector<Extensao> extensoes = geraExtensoes (alunos, professores);

    vector<Trabalho> trabalhos = geraTrabalhos (extensoes);

    cout << "Comecou a gravar" << endl;

    csv_Area_de_Conhecimento (areas);

    csv_Local (locais);

    csv_Professor (professores);

    csv_Curso (cursos);

    csv_Disciplina (disciplinas);

    csv_Rel_Pre_Requisito (preRequisitos);

    csv_Rel_Curso_Disciplina (cursoDisciplinas);

    csv_Aluno (alunos);

    csv_Turma (turmas);

    csv_Rel_Turma_Aluno (turmaAlunos);

    csv_Extensao (extensoes);

    csv_Trabalho (trabalhos);

    cout << "Acabou de gravar" << endl;

    return 0;
}


