// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#define PORT 8080
#define TOTAL_CHALLENGES 10
#define ANSI_COLOR_BLACK "\x1b[30m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
static void checkAnswer(char *msg, char *expectedAnswer);

static void clear();
static void play();
static void initSocket();
static void challenge1();
static void challenge2();
static void challenge3();
static void challenge4();
static void challenge5();
static void challenge6();
static void challenge7();
static void challenge8();
static void challenge9();
static void challenge10();
static int my_socket;
static void (*challenges[])(void) = {challenge1, challenge2, challenge3, challenge4, challenge5, challenge6, challenge7, challenge8, challenge9, challenge10};
static char *answers[] = {"entendido\n", "itba\n", "M4GFKZ289aku\n", "fk3wfLCm3QvS\n", "too_easy\n", ".RUN_ME\n", "K5n2UFfpFMUN\n", "BUmyYq5XxXGt\n", "u^v\n", "chin_chu_lan_cha\n"};
int main(int argc, char const *argv[])
{
    initSocket();
    play();
    return 0;
}

static void initSocket()
{
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((my_socket = accept(server_fd, (struct sockaddr *)&address,
                            (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
}

static void play()
{
    int currentChallenge = 0;
    while (currentChallenge < TOTAL_CHALLENGES)
    {
        challenges[currentChallenge]();
        currentChallenge++;
    }

    printf("Ganaste wey\n");
}

static void checkAnswer(char *msg, char *expectedAnswer)
{
    char answer[248] = {0};
    int done = 0;
    int valread;
    while (!done)
    {
        valread = read(my_socket, answer, 248);
        if (valread < 0)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        if (!strcmp(answer, expectedAnswer))
        {

            done = 1;
        }
        else
        {

            printf("Respuesta incorrecta: %s\n", answer);
            sleep(2);
            clear();
            puts(msg);
        }
    }
}

static void clear()
{
    system("clear");
}
static void challenge1()
{
    clear();
    char *msg = "--------------- DESAFIO ---------------\nBienvenidos al TP3 y felicitaciones,ya resolvieron el primer acertijo.\n\nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\nAdemás tendrán que investigar otras preguntas para responder durante la defensa.\nEl desafío final consiste en crear un programa que se comporte igual que yo,es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos.\n No basta con esperar la respuesta.\nAdemás, deberán implementar otro programa para comunicarse conmigo.\n\nDeberán estar atentos a los easter eggs.\n\nPara verificar que sus respuestas tienen el mismo formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n\n------PREGUNTA PARA INVESTIGAR------\n¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse ?\n";
    puts(msg);
    checkAnswer(msg, answers[0]);
}
static void challenge2()
{
    clear();
    char *msg = "--------------- DESAFIO ---------------\nThe Wire S1E5\n5295 888 6288\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n";
    puts(msg);
    checkAnswer(msg, answers[1]);
}
static void challenge3()
{
    clear();
    char *msg = "--------------- DESAFIO ---------------\nhttps://ibb.co/tc0Hb6w\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n";
    puts(msg);
    checkAnswer(msg, answers[2]);
}
static void challenge4()
{
    clear();
    char *msg = "--------------- DESAFIO ---------------\nEBADF. . .\nwrite: Bad file descriptor\n----- PREGUNTA PARA INVESTIGAR -----\n¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n";
    puts(msg);
    checkAnswer(msg, answers[3]);
}
static void challenge5()
{
    clear();
    char *msg = "--------------- DESAFIO ---------------\nrespuesta = strings:277\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n";
    puts(msg);
    checkAnswer(msg, answers[4]);
}
static void challenge6()
{
    clear();
    char *msg = "--------------- DESAFIO ---------------\n.data .bss .comment ? .shstrtab .symtab .strtab\n\n----- PREGUNTA PARA INVESTIGAR -----\nUn servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?\n";
    puts(msg);
    checkAnswer(msg, answers[5]);
}
static void challenge7()
{

    clear();
    char *msg = "--------------- DESAFIO ---------------\nFilter error\n\n9LD=a rxgVSR[{eMsFUE$y<_1bbU1p+C:{u[8>k7mies__nx5%Jr3]tIRq[a%gk diD[e\\ K`qsj\\ Vl'%K6+WH~{=,gqbw58'n2S7\"hUFLffp]C(v$\\IFyHi#gfMUbN'9>K:GD[%rrCpH5e'I+az!f\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n";
    puts(msg);
    checkAnswer(msg, answers[6]);
}
static void challenge8()
{
    clear();
    char msg[248] = {0};

    sprintf(msg, "--------------- DESAFIO ---------------\n%s %s %s\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n", ANSI_COLOR_BLACK, answers[7], ANSI_COLOR_RESET);
    checkAnswer(msg, answers[7]);
}
static void challenge9()
{

    clear();
    char *msg = "--------------- DESAFIO ---------------\nLatexme\n\nSi\n \\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\nentonces\ny = \n\n----- PREGUNTA PARA INVESTIGAR -----\nsockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n";
    puts(msg);
    checkAnswer(msg, answers[8]);
}
static void challenge10()
{

    int done = 0;
    int valread;
    char answer[248] = {0};
    int gcc = 1, diff = 1;

    char *msg_start = "--------------- DESAFIO ---------------\nquine";
    while (!done)
    {
        while (gcc)
        {
            clear();
            puts(msg_start);
            gcc = system("gcc -Wall quine.c -o quine");
            if (gcc == 0)
            {

                puts("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");

                diff = system("./quine | diff ./quine.c -");

                if (diff == 0)
                {
                    char *msg = "La respuesta es chin_chu_lan_cha\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Cuáles son las características del protocolo SCTP?\n";
                    puts(msg);
                    checkAnswer(msg, answers[9]);
                    done = 1;
                }
                else
                {
                    char *errorMsg = "\ndiff encontró diferencias.\nENTER para reintentar\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Cuáles son las características del protocolo SCTP?\n";
                    puts(errorMsg);

                    valread = read(my_socket, answer, 248);
                    if (valread < 0)
                    {
                        perror("read");
                        exit(EXIT_FAILURE);
                    }
                    if (strcmp(answer, "\n"))
                    {
                        printf("Respuesta incorrecta: %s\n", answer);
                        sleep(2);
                    }
                }
            }
            else
            {
                char *errorMsg = "\nENTER para reintentar\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Cuáles son las características del protocolo SCTP?\n";
                puts(errorMsg);

                valread = read(my_socket, answer, 248);
                if (valread < 0)
                {
                    perror("read");
                    exit(EXIT_FAILURE);
                }
                if (strcmp(answer, "\n"))
                {
                    printf("Respuesta incorrecta: %s\n", answer);
                    sleep(2);
                }
            }
        }
    }
}
