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
#define TOTAL_CHALLENGES 12
#define ANSI_COLOR_BLACK "\x1b[30m"
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
static void challenge11();
static void challenge12();
static int my_socket;
static void (*challenges[])(void) = {challenge1, challenge2, challenge3, challenge4, challenge5, challenge6, challenge7, challenge8, challenge9, challenge10, challenge11, challenge12};
static char *answers[] = {"entendido\n", "itba\n", "M4GFKZ289aku\n", "fk3wfLCm3QvS\n", "too_easy\n", ".RUN_ME\n", "K5n2UFfpFMUN\n", "BUmyYq5XxXGt\n", "u^v\n", "chin_chu_lan_cha\n","gdb_rules\n","normal\n"};
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

    clear();

    printf("Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n\n");
}

static void checkAnswer(char *msg, char *expectedAnswer)
{
    char answer[1024] = {0};
    int done = 0;
    int valread;
    while (!done)
    {
        valread = read(my_socket, answer, 1024);
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
    clear();
    char *msg = "------------- DESAFIO -------------\nquine\n\n¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\nLa respuesta es chin_chu_lan_cha\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Cuáles son las características del protocolo SCTP?\n";
    puts(msg);
    checkAnswer(msg, answers[9]);
}
static void challenge11() 
{
    clear();
    char *msg = "------------- DESAFIO -------------\nb gdbme y encontrá el valor mágico\n\nENTER para reintentar.\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Qué es un RFC?\n";
    puts(msg);
    checkAnswer(msg, answers[10]);
}
static void challenge12() 
{
    clear();
    char *msg = "------------- DESAFIO -------------\nMe conoces\n\n-0.136980 -1.282920 -0.394569 0.717118 0.805825 -0.287751 -0.683856 0.096541 -0.279493 -1.149283 -0.163998 -0.668280 0.218507 0.315766 0.296368 -0.513552 -0.446078 -1.309865 -1.096214 0.136036 0.484351 -1.953742 0.354675 -1.174898 -1.604113 0.012096 -0.533597 0.961009 -1.591730 0.159715 0.120232 -0.470586 0.861831 -0.276906 1.025978 -0.514714 -1.612264 0.253893 0.960719 -0.564907 -0.833374 -0.414025 -0.408914 0.503160 -1.233873 -0.589026 -0.155975 0.949014 1.708698 0.094869 -0.083980 1.551881 0.440481 -0.087296 -1.769622 -0.093954 0.505691 -0.343614 -0.900952 -0.408311 -0.061748 -2.047539 -0.080748 0.006772 -1.691690 0.562773 -0.412597 -0.140379 0.106185 -2.104393 0.985058 -1.348023 -0.493562 -0.355428 1.982275 0.697867 0.703369 0.762327 -0.853049 -0.271903 0.254706 -0.296882 0.017845 -0.727418 -0.145965 -0.243334 0.006766 -1.737365 0.434443 0.592068 -1.049505 -0.328402 -1.718548 -0.154445 0.474615 -0.070352 1.672447 1.238663 0.562301 0.200517 -0.682895 0.803853 -0.836989 -0.715442 0.586527 0.033706 1.333589 -1.078752 -0.266725 -0.887840 0.213187 1.556880 -0.011245 2.647909 -0.771970 0.677987 0.383971 -0.215581 0.940214 0.689056 0.143423 0.398305 0.216937 -0.945986 0.413563 -1.372371 -1.470783 -0.925631 -1.042650 0.683921 -1.523050 0.129654 0.060627 1.740561 -0.021019 0.065974 0.916831 -0.530627 -0.938221 1.749178 -0.018590 0.149987 -0.466671 1.335411 0.070605 0.649894 -0.731365 0.137676 1.237858 -0.070429 0.687003 -0.036065 1.440428 -0.730450 0.691434 -0.333820 -0.262788 0.267887 0.386408 -0.627991 -0.816910 0.896482 -1.844386 -0.541805 -0.742728 0.249757 0.666453 1.219857 0.387499 1.319778 0.232683 0.729525 0.132056 0.190321 -2.365110 0.157942 2.269373 0.135329 -1.038388 0.568555 -0.250977 1.472976 -0.662852 -0.567864 0.147904 -0.110775 -0.312367 -0.296044 -0.977572 -1.894810 -2.012518 0.757032 0.876968 0.567140 0.157044 0.038134 -0.279091 -0.725325 -2.371207 1.125250 -0.695939 0.648826 -0.278915 -1.316506 -0.093478 0.333122 -0.107015 -1.518674 -1.161289 0.968574 0.285027 0.154379 -1.103117 -0.606612 -0.497947 -1.614745 -0.506725 1.003860 -1.770358 1.603200 0.108361 -0.462864 0.070240 1.130492 -0.046190 -0.339343 -1.068589 0.586163 0.245292 -0.035279 -0.512612 -0.586451 0.664192 1.570432 -1.329050 -0.970536 0.749787 1.096772 0.662483 1.417574 0.192851 -0.610143 -0.213710 0.391108 -2.050985 -0.219652 -0.218940 0.150824 1.861015 -0.561723 1.142964 0.562478 0.089145 -0.601267 -0.638214 1.144194 -0.638002 -1.244136 -0.143732 -0.415576 -1.388381 2.228619 0.014184 0.809176 -0.806290 1.116513 -0.398455 -1.952647 -1.572667 0.301582 -0.013052 0.673942 -1.048692 1.173201 1.355946 -0.642431 0.712880 -1.245470 0.722286 -0.233180 0.764609 0.661842 -1.689465 -0.693285 -0.463896 -0.987923 -0.351061 0.162466 -1.258366 -1.435263 0.619986 0.274974 -1.797494 -0.823465 1.071677 0.208218 0.023230 1.277507 0.814351 -1.041272 1.298293 1.556669 -0.818128 1.377184 -0.738219 -0.609039 -0.466065 0.520920 0.176364 0.117207 -1.627682 1.335151 0.015516 -1.523706 -0.754681 0.151219 0.843631 -0.111153 -0.771509 0.277792 -0.988729 0.826597 1.207182 0.003987 -1.384527 -2.586566 -0.441232 -1.145719 -1.682149 0.426213 1.339748 -1.381756 -0.194090 -0.382418 0.174088 -0.155934 0.319139 0.271587 -0.126069 -0.715575 -0.347262 0.121495 -1.818415 0.013643 0.044738 1.783761 -0.636918 0.855995 -0.808211 -0.555273 0.895371 -0.347371 -0.267927 0.767902 0.115915 -1.289644 1.209605 -1.249437 -0.052045 -0.730744 0.176948 1.194413 1.351064 1.276682 -0.048482 -0.732469 -0.655457 -0.626736 0.743562 -1.318682 -0.651254 1.575561 -0.884752 0.678061 -0.117759 0.164217 1.966538 -0.711730 -1.485365 0.707722 -0.913125 1.332989 1.984686 0.655078 0.320328 -1.098094 -1.018376 0.492706 -0.157117 0.783381 0.528776 -0.286505 -0.274876 2.449061 0.516520 0.329713 0.443387 2.442237 -0.511308 0.073262 0.907736 0.756828 0.725164 -0.176744 -0.101889 0.964606 2.147441 0.714053 0.140145 -0.013419 -0.063627 0.305607 0.983328 -0.513946 -0.353615 1.065417 -0.363729 -0.612271 -0.267029 0.080888 -0.306054 1.594783 1.208848 0.093672 0.518047 0.006752 0.571758 0.586191 -0.653652 -0.230474 1.260912 1.827943 0.694490 -0.429912 -0.161727 -1.121177 0.149914 0.268188 -0.724200 -1.371362 -0.396071 1.468806 1.735346 2.088992 -0.356043 -1.046574 -0.746533 0.655062 1.090103 0.215651 1.249778 0.978359 0.307082 -1.431358 -0.105407 -0.288698 -0.714082 0.432651 -0.006488 -1.328237 -0.658942 1.527652 0.814718 1.854387 -1.877027 -0.771545 1.167197 0.098789 0.621017 0.488216 -0.048641 0.221119 -2.469552 0.003459 1.241203 0.019339 0.584348 0.371145 1.788326 -0.581408 0.576548 0.593607 -0.602947 -1.080660 1.028965 -0.446645 -0.420093 -0.118310 0.779171 -0.168241 1.111721 -0.310678 2.220675 0.121135 2.823398 -1.152967 -0.355355 -0.683924 0.098839 -1.495890 0.690515 -0.625656 0.781237 1.733782 0.810697 -1.158489 -0.064674 1.533252 0.610705 0.780060 1.122251 0.780395 1.512474 1.170336 0.120069 -1.075659 -0.140310 -0.449853 1.435764 -1.064949 1.661874 -0.154451 0.702094 -1.228484 -0.462106 0.913174 0.092106 -0.075546 -0.884908 -0.410161 0.398638 0.656319 -0.753703 0.178855 0.323372 1.665562 1.284232 1.507956 -0.890952 -0.310921 1.166096 1.140717 -0.713405 -0.493339 -0.315663 0.743315 -0.979684 1.745988 1.018007 0.118999 2.734832 0.241575 1.793191 -1.503851 -0.539145 0.805357 0.860117 0.023423 -0.947832 -0.697825 0.034174 -1.250363 -0.634624 -0.086603 -1.077502 -1.105339 -0.118512 -0.369145 0.457533 2.220093 0.000817 2.736256 0.559387 -1.078930 0.235582 -0.759114 1.220861 -0.900351 -0.439035 -0.025215 2.321724 -0.806132 -1.212606 -1.742749 -0.444810 -0.986347 -2.507155 0.782953 0.590007 1.422727 0.962492 -0.594197 -0.508252 1.424125 0.028808 -1.373714 0.735873 0.335604 0.999315 -1.305840 0.724568 -2.287600 -0.731808 0.373285 -0.900505 0.367756 -1.028946 -0.085849 1.439293 -0.779125 0.446188 -0.258010 0.497882 1.033091 1.571536 -1.050092 -0.629720 0.394292 -0.345375 0.163670 -0.196063 -0.427678 -0.827203 -1.616518 0.578628 -2.378417 0.685615 -1.618498 -0.429467 0.666703 0.057366 0.836437 -0.081788 1.128899 1.050512 -0.340119 0.549937 0.213751 0.688477 -0.381219 -0.677567 0.214858 1.542340 0.905889 0.706690 2.108689 -0.984374 0.369167 -0.843512 0.415802 -0.440406 0.887389 -1.611191 -0.216998 0.362605 0.053073 0.807961 -0.106470 0.414671 -0.490233 1.468737 -0.869063 1.577888 0.661788 1.262875 0.276998 0.069013 -0.643051 -0.473383 1.493275 0.262504 -0.264444 -2.622033 2.176849 1.046172 -0.646065 0.189270 1.779829 1.180060 -0.264450 0.365712 -0.440067 0.478291 0.288457 0.644698 -0.706225 1.138947 0.530896 0.833960 1.177720 -1.164404 0.324237 0.462918 0.448508 0.432099 -0.166026 0.273150 -0.034857 0.093484 0.109517 0.199765 1.153050 -1.479623 1.555837 -0.987411 -1.818974 1.657385 1.316660 -0.232239 -1.439410 -1.328932 1.102845 -0.939127 -0.557783 0.279437 1.280106 -0.001155 -0.580396 -1.543522 0.592857 -0.337209 1.360193 0.639018 2.234526 1.850487 -0.271888 0.561884 0.527762 -0.142252 0.121859 2.314806 0.515076 0.838801 1.380723 -1.115303 -0.409395 0.240632 0.458907 -0.189277 1.327242 1.176924 1.081551 0.627553 -0.036682 2.169364 0.805226 -0.359306 -1.653651 -1.248222 0.873790 -0.237282 1.660054 -1.234135 -1.138043 -0.403315 -0.665870 0.498741 0.076945 -0.116212 -0.272820 0.854385 -0.505103 1.306659 1.029997 -0.359902 -0.754086 0.241568 -0.907689 -1.011057 -0.768683 1.413683 -0.583503 0.028707 -1.095202 0.181983 -0.911142 0.253420 -0.544827 -1.697777 -1.749917 1.502865 2.231307 -0.545843 -0.878519 1.187206 0.575717 -1.131879 -0.372455 0.593030 0.110376 -0.020864 -0.052357 -0.581803 -2.279427 0.774324 0.443106 1.106952 1.336476 0.096699 -1.075213 0.241848 -0.183662 -0.437289 -0.921570 -1.431447 0.383446 0.244111 0.083507 1.202455 -0.633355 1.558089 -0.050374 1.827634 -0.618988 -0.533386 0.560069 1.022434 -0.895438 -0.475795 -0.136699 0.003327 0.427006 1.550013 -1.676474 0.550898 1.965658 0.376188 1.528295 -3.014172 0.607516 0.281873 -0.827045 0.509526 -0.407733 0.024046 -0.621621 3.372617 0.756480 0.487912 -0.134447 -0.061476 0.378358 0.814495 -0.368119 -1.047230 -1.113285 0.305416 -2.074142 0.150860 -0.322761 0.803357 -0.462209 1.852962 0.627525 -0.439060 0.039920 -1.910964 -0.089313 -1.037548 1.189333 0.284659 -0.958735 -0.562693 2.172078 0.897794 -0.724754 -0.299508 2.062790 0.579378 -0.166965 -1.163180 -0.819718 0.720886 -2.148942 -1.626840 0.455544 -0.217494 -0.921457 -0.098179 -0.673688 0.660560 -1.657541 0.462058 -0.799886 -0.093010 0.192592 1.022480 -0.942541 -0.365581 0.156355 -2.528084 -0.918318 0.464075 0.440043 -0.703117 -0.113502 -1.152730 -0.266509 -0.601282 -0.539016 0.197518 -0.286068 0.081943 1.015130 0.669937 0.040157 -0.273010 -1.859016 1.573513 0.958671 1.399957 1.023990 1.102131 1.514523 0.772652 0.844225 -0.435780 -0.124128 0.600742 -0.765112 -0.444464 -1.738072 -0.156308 1.722643 -1.546327 -0.220288 0.852951 1.317950 -1.333346 1.923590 -0.182770 -0.208281 -0.129768 -0.686547 0.112204 -2.373625 0.343215 1.642134 0.372203 -0.002058 0.307091 -0.214223 -0.082333 -1.648367 -0.660630 1.328126 -1.787840 0.747054 -0.075750 -0.157674 0.845732 0.644713 -0.285505 -0.295250 0.743007 0.163653 -0.648656 -0.809330 0.086259 0.409401 -2.193061 0.432742 -0.254921 1.618445 1.880097 -0.657186 0.222312 1.227749 -0.983517 -0.441275 1.187244 0.187301 -0.703442 0.933974 -1.736775 -0.012022 -0.486157 1.366125 -1.366909 0.079369 -0.168506 -0.183323 0.560342 0.386962 -1.122550 1.148932 -1.052776 0.352757 0.025662 1.585595 0.271342 1.317280 -0.330154 0.503108 1.038129 2.144470 0.541637 0.140621 -0.171379 -2.318552 \n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Fue divertido?\n";
    puts(msg);
    checkAnswer(msg, answers[11]);
}