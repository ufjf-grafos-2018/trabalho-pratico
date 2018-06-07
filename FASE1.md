# Trabalho prático grafos

## Trabalho Prático – Fase 1

### Objeto do trabalho
desenvolver um Tipo Abstrato de Dados - TAD ou uma classe que implemente o conjunto de funcionalidades apresentados a seguir e outras a serem requeridas ao longo do curso.

### Orientações:
 - seu TAD deve ser capaz de representar grafos (possivelmente digrafos, ponderados ou não) utilizando inicioLista de adjacência;
 - o código deve ser desenvolvido em linguagem C ou C++ e deve estar bem comentado (código sem documentação será penalizado na nota);
 - o programa principal que usará o TAD deve ler os dados do grafo (ou digrafo) a partir de arquivo texto, conforme  odelo indicado neste documento;
 - para cada funcionalidade solicitada, seu programa deve apresentar uma opção em um menu apresentado no display;
 - todo o código deve ser desenvolvido utilizando o padrão ANSI da linguagem C/C++;
 - o padrão para a execução a ser utilizado pelo professor será a linha abaixo, executada em ambiente Linux ou IOS:
`o ./grafosGrupoX <nome_arquivo_entrada> <nome_arquivo_saida>`
onde **X** é o número do grupo; `<nome_arquivo_entrada>` é o nome do arquivo que contém as informações  do grafo; e `<nome_arquivo_saida>` é o arquivo onde será gravado o grafo armazenado na memória ao término do programa ou após o usuário escolher a opção de menu para salvar o grafo.
 - O grupo deve enviar um único arquivo com extensão ZIP para o e-mail indicado em sala de aula, cujo assunto da mensagem seja *“Trabalho Grafos Grupo X – 2018-1”*, onde **X** indica o número do grupo. Nota: no arquivo zip deve ter incluso apenas os arquivos com extensão c, cpp ou h.
 - ao final do trabalho, um relatório, conforme o modelo látex a ser apresentado em sala de aula, deve ser enviado ao professor para o e-mail indicado no item anterior em mensagem cujo assunto deve ser *“Relatório Grafos Grupo X – 2017-3”*, onde **X** indica o numero do grupo. O relatório deve informar as decisões de projeto e de implementação (fundamentadas nas dificuldades enfrentadas), além das saídas do programa para as  funcionalidades solicitadas. O relatório não deve ultrapassar 15 páginas, não deve ter listagem de código fonte e todo pseudocódigo inserido deve ter as linhas numeradas.

**Observação:** o trabalho é em grupo e deve ser feito sempre sob a orientação do professor, embora o grupo possa e deva procurar trocar ideias entre si e levar ao professor as decisões de projeto pra serem discutidas.

### Requisitos
O TAD ou classe deve apresentar as seguintes funcionalidades:
 - a – leitura de arquivo (conforme entrada) e escrita em arquivo no mesmo modelo da entrada;
 - b – inclusão e exclusão de nó e de aresta;
 - c – retornar o grau de um dado nó informado pelo usuário (caso seja um dígrafo, informar grau de entrada e de saída);
 - d – verificar a k-regularidade do grafo (k informado pelo usuário);
 - e – informar a ordem do grafo;
 - f – informar se o grafo é trivial;
 - g – informar se o grafo é nulo;
 - h – mostrar a vizinhança aberta de um dado nó informado pelo usuário;
 - i – mostrar a vizinhança fechada de um dado nó informado pelo usuário;
 - j – verificar se o grafo é um multigrafo;
 - k – verificar se o grafo é completo;
 - l – verificar se o grafo é bipartido;
 - m – apresentar a sequência de graus;

### Formato do arquivo de entrada:


    5
    1 2 15
    3 4 11
    4 1 12
    4 5 112
    5 2 5
    5 1 25
    1 3 48
    2 4 1
    2 3 6
    3 5 71

Neste exemplo, temos um grafo ponderado nas arestas, onde a primeira linha indica que o grafo tem 5 vértices.  Cada uma das demais linhas traz os dois vértices que formam arestas, seguidos pelo peso da mesma.

Qualquer dúvida, enviar e-mail ou procurar o professor da disciplina ou o tutor.

-----
Juiz de Fora, 24 de março de 2018.