/*
 * matriz.cpp
 *
 *  Created on: 15 de out de 2017
 *      Author: nocera
 */

#include <iostream>
#include <cstdlib>
#include "classes.h"

using namespace std;

Area_de_Conhecimento::Area_de_Conhecimento (int cd_Area, string nm_Area): cd_Area (cd_Area), nm_Area(nm_Area) {}

Local::Local (int cd_Local, int nu_Telefone, string nm_Local): cd_Local(cd_Local), nu_Telefone(nu_Telefone)
              , nm_Local(nm_Local) {}

Pessoa::Pessoa (int cd_Pessoa, string nm_Pessoa): cd_Pessoa (cd_Pessoa), nm_Pessoa(nm_Pessoa) {}

Professor::Professor (int cd_Professor, Pessoa cd_Pessoa, Local cd_Local, string nm_Site
                      , string nm_Email, int nu_SIAPE, string nm_Titulo, string nm_Classe): cd_Professor(cd_Professor)
                                                                                          , cd_Pessoa(cd_Pessoa)
                                                                                          , cd_Local(cd_Local)
                                                                                          , nm_Site(nm_Site)
                                                                                          , nm_Email(nm_Email)
                                                                                          , nu_SIAPE(nu_SIAPE)
                                                                                          , nm_Titulo(nm_Titulo)
                                                                                          , nm_Classe(nm_Classe) {}

Curso::Curso (int cd_Curso, Area_de_Conhecimento cd_Area, Professor cd_Coordenador, string nm_Curso): cd_Curso(cd_Curso), cd_Area(cd_Area)
                                                                                    , cd_Coordenador(cd_Coordenador)
                                                                                    , nm_Curso(nm_Curso) {}

Disciplina::Disciplina (int cd_Disciplina, string cd_Codigo, int hh_Carga_Horaria, string nm_Ementa, string nm_Bibliografia
                        , string nm_Disciplina): cd_Disciplina(cd_Disciplina), cd_Codigo(cd_Codigo)
                                                , hh_Carga_Horaria(hh_Carga_Horaria), nm_Ementa(nm_Ementa)
                                                , nm_Bibliografia(nm_Bibliografia), nm_Disciplina(nm_Disciplina) {}



Rel_Curso_Disciplina::Rel_Curso_Disciplina (Curso cd_Curso, Disciplina cd_Disciplina, string nm_Obrigatoriedade) :
                                            cd_Curso(cd_Curso), cd_Disciplina(cd_Disciplina), nm_Obrigatoriedade(nm_Obrigatoriedade) {}

Rel_Pre_Requisito::Rel_Pre_Requisito (Disciplina cd_Disciplina, Disciplina cd_Pre_Requisito): cd_Disciplina(cd_Disciplina)
                                                                                            , cd_Pre_Requisito(cd_Pre_Requisito) {}

Aluno::Aluno (int cd_Aluno, Pessoa cd_Pessoa, Professor cd_Orientador, Curso cd_Curso): cd_Aluno(cd_Aluno), cd_Pessoa(cd_Pessoa)
                                                                                      , cd_Orientador(cd_Orientador), cd_Curso(cd_Curso) {}

Turma::Turma (int cd_Turma, Disciplina cd_Disciplina, Local cd_Local, Professor cd_Professor, int hh_Horario, int nu_Vagas
              , int nu_Turma): cd_Turma(cd_Turma), cd_Disciplina(cd_Disciplina), cd_Local(cd_Local), cd_Professor(cd_Professor)
              , hh_Horario(hh_Horario), nu_Vagas(nu_Vagas), nu_Turma(nu_Turma) {}

Rel_Turma_Aluno::Rel_Turma_Aluno (Turma cd_Turma, Aluno cd_Aluno, int nu_Nota): cd_Turma(cd_Turma), cd_Aluno(cd_Aluno)
                                                                              , nu_Nota(nu_Nota) {}

Extensao::Extensao (int cd_Extensao, Aluno cd_Aluno, Professor cd_Orientador, string nm_Extensao): cd_Extensao(cd_Extensao)
                                                                                                 , cd_Aluno(cd_Aluno)
                                                                                                 , cd_Orientador(cd_Orientador)
                                                                                                 , nm_Extensao(nm_Extensao) {}

Trabalho::Trabalho (int cd_Trabalho, Extensao cd_Extensao, int nu_Nota, string nm_Trabalho): cd_Trabalho(cd_Trabalho)
                                                                                           , cd_Extensao(cd_Extensao)
                                                                                           , nu_Nota(nu_Nota)
                                                                                           , nm_Trabalho(nm_Trabalho) {}
