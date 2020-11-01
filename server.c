// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#define PORT 8080
#define TOTAL_CHALLENGES 20

static void play(int socket);
static void init();
struct challenge
{
    char *msg;
    char *answer;
} challenges[TOTAL_CHALLENGES];

static int currentChallenge = 0;
int main(int argc, char const *argv[])
{
    int server_fd, new_socket;
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
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    init();
    play(new_socket);
    return 0;
}

static void play(int socket)
{
    struct challenge *currChall;

    char *expectedAns;
    int valread, solved = 0;
    char receivedAnswer[1024] = " ";
    char wrongAnsMsg[1048] = "Respuesta incorrecta: ";

    while (currentChallenge < TOTAL_CHALLENGES)
    {
        currChall = &challenges[currentChallenge];
        if (currChall == NULL)
        {
            return;
        }
        printf("%s\n\n\n\n", currChall->msg);

        expectedAns = currChall->answer;
        solved = 0;
        while (solved == 0)
        {

            valread = read(socket, receivedAnswer, 1024);
            if (valread < 0)
            {
                perror("read");
                exit(EXIT_FAILURE);
            }
            else if (valread > 0)
            {

                if (!strcmp(receivedAnswer, expectedAns))
                {
                    solved = 1;
                    currentChallenge++;
                }
                else
                {
                    strcat(wrongAnsMsg, receivedAnswer);
                    printf("\n\n\n\n%s", currChall->msg);
                    printf("\n\n\n%s", wrongAnsMsg);
                    sleep(3);
                    printf("%s\n\n\n\n", currChall->msg);
                    wrongAnsMsg[22] = 0;
                }
            }
        }
    }
}

static void init()
{
    challenges[0].msg = "--------------- DESAFIO ---------------\nBienvenidos al TP3 y felicitaciones,ya resolvieron el primer acertijo.\n\nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\nAdemás tendrán que investigar otras preguntas para responder durante la defensa.\nEl desafío final consiste en crear un programa que se comporte igual que yo,es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos.\n No basta con esperar la respuesta.\nAdemás, deberán implementar otro programa para comunicarse conmigo.\n\nDeberán estar atentos a los easter eggs.\n\nPara verificar que sus respuestas tienen el mismo formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n\n------PREGUNTA PARA INVESTIGAR------\n¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse ?\n";
    challenges[0].answer = "entendido\n";
}
