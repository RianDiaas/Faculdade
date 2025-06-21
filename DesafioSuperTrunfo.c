#include <stdio.h>
#include <string.h> //Biblioteca para manipulação de Strings, Vou usar esse repositorio no fgets (para poder casdastra nomes compostos como São Paulo.)

// vamos usar definições para brincar com cores através do ANSI 
#define RED "\033[31m" 
#define RESET "\033[0m"
#define GREEN "\033[0;32m"

int main(){

//Saudações ao usuario.
printf("Olá, Seja Bem Vindo ao Super Trunfo!\n");
printf("Vamos Começar!\n");
printf("\n"); // linha em branco para melhor organização

// Vamos Criar as Variavéis da Carta 1
char Estado1[3], codigo1[5], nomedacidade1[20];
float pib1, area1;
int pontosturisticos1;
unsigned long int populacao1;

// Vamos Criar as Variavéis da Carta 2
char Estado2[3], codigo2[5], nomedacidade2[20];
float pib2, area2;
int pontosturisticos2;
unsigned long int populacao2;

// Variaveis usadas ao longo do codigo: 
float densidade1, pibpc1, densidade2, pibpc2;
float superpoder1, superpoder2;
int cartaVencedor;

// Inicio do Cadastro da carta 1
printf (RED "-------Cadastro da Carta 1:-------\n\n" RESET);

printf("Digite seu Estado:");
scanf ("%2s", Estado1); //limitado a 2 caracteres
getchar(); // Limpa o \n do buffer.

printf("Qual o Codigo da Sua Carta?");
scanf("%4s", codigo1);//limitado a 4 caracteres
getchar();

printf("Nome da Cidade: ");
fgets(nomedacidade1, sizeof(nomedacidade1), stdin); // essa linha le um texto direto do teclado, e armazena em nomedacidade1.
nomedacidade1[strcspn(nomedacidade1, "\n")] = '\0'; // Remove '\n' que a função fgets captura quando o usuario aperta enter.

printf("Quantidade de Habitantes (Digite sem pontos ou Virgulas):");
scanf("%lu", &populacao1);
getchar();

printf("Digite a Área da Cidade (em Km²) Ex: 12.65: ");
scanf("%f", &area1);
getchar();

printf("Digite o PIB da Cidade (Em Bilhões de Reais):");
scanf("%f", &pib1);
getchar();

printf("Digite o Número de Pontos Turísticos: ");
scanf("%d", &pontosturisticos1);
getchar();

printf("\n");//linha em branco para melhor organização e exibição.

// Inicio do Cadastro da carta 2
printf (RED "-------Cadastro da Carta 2:-------\n\n" RESET);

printf("Digite seu Estado:");
scanf ("%2s", Estado2);
getchar();

printf("Qual o Codigo da Sua Carta?");
scanf("%4s", codigo2);
getchar();

printf("Nome da Cidade: ");
fgets(nomedacidade2, sizeof(nomedacidade2), stdin);
nomedacidade2[strcspn(nomedacidade2, "\n")] = '\0'; // mesmo conjunto de instruções utilizado na primeira cidade.

printf("Quantidade de Habitantes (Digite sem pontos ou Virgulas):");
scanf("%lu", &populacao2);
getchar();

printf("Digite a Área da Cidade (em Km²) Ex: 12.65: ");
scanf("%f", &area2);
getchar();

printf("Digite o PIB da Cidade (Em Bilhões de Reais):");
scanf("%f", &pib2);
getchar();

printf("Digite o Número de Pontos Turísticos: ");
scanf("%d", &pontosturisticos2);
getchar();

printf("\n");

/*
Vamos calcular a densidade populacional e o pib per capita das duas cartas, irei fazer de forma unificada
Para não esquecer: 
Densidade = população / area 
PIB per Capita = PIB / população
*/

// Calculo carta 1
densidade1 = (float)populacao1 / area1;
pibpc1 = (pib1 * 1000000000) / populacao1; // uso a multiplicação por 1 bilhão para transforma em um dado inteiro pois na entrada estou pedindo como dado simples
// exemplo foi digitado (300 bilhoes) ele vai transformar a escrita em 300.000.000.000 

// Calculo carta 2
densidade2 = (float)populacao2 / area2;
pibpc2 = (pib2 * 1000000000) / populacao2;

// superpoder
superpoder1 = (float)populacao1 + area1 + pib1 + (float)pontosturisticos1 + pibpc1 + (1 / densidade1);
superpoder2 = (float)populacao2 + area2 + pib2 + (float)pontosturisticos2 + pibpc2 + (1 / densidade2);

/* Agora vamos a exibição
Começando da Carta 1*/
printf(GREEN "----- Carta 1 -----\n" RESET);
printf("Estado: %s\n", Estado1);
printf("Codigo da Carta: %s\n", codigo1);
printf("Nome da cidade: %s\n", nomedacidade1);
printf("Quantidade de Habitantes: %lu\n", populacao1);
printf("Área da Cidade (em Km²): %.2f \n" ,area1);
printf("PIB: %.2f Bilhões de Reais.\n", pib1);
printf("Numero de Pontos Turisticos: %d\n",pontosturisticos1);
printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
printf("PIB per Capita: %.2f reais\n", pibpc1);
printf("Super Poder: %.2f\n", superpoder1);

printf("\n");

// Exibição dos dados da carta 2
printf(GREEN "----- Carta 2 -----\n" RESET);
printf("Estado: %s\n", Estado2);
printf("Codigo da Carta: %s\n", codigo2);
printf("Nome da cidade: %s\n", nomedacidade2);
printf("Quantidade de Habitantes: %lu\n", populacao2);
printf("Área da Cidade (em Km²): %.2f \n" ,area2);
printf("PIB: %.2f Bilhões de Reais.\n", pib2);
printf("Numero de Pontos Turisticos: %d\n",pontosturisticos2);
printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
printf("PIB per Capita: %.2f reais\n", pibpc2);
printf("Super Poder: %.2f\n", superpoder2);

printf("\n");

// Comparações - inicialização aqui para evitar problemas
int venceuPopulacao = populacao1 > populacao2;
int venceuArea = area1 > area2;
int venceuPIB = pib1 > pib2;
int venceuPontosTuristicos = pontosturisticos1 > pontosturisticos2;
int venceuDensidade = densidade1 < densidade2; // vence o menor.
int venceuPIBperCapita = pibpc1 > pibpc2;
int venceuSuperPoder = superpoder1 > superpoder2;

printf(GREEN "==================== COMPARAÇÃO DAS CARTAS ====================\n" RESET);
printf("População: Carta 1 venceu: (%d)\n", venceuPopulacao);
printf("Área: Carta 1 venceu: (%d)\n", venceuArea);
printf("PIB: Carta 1 venceu: (%d)\n", venceuPIB);
printf("Pontos Turísticos: Carta 1 venceu: (%d)\n", venceuPontosTuristicos);
printf("Densidade Populacional: Carta 1 venceu: (%d)\n", venceuDensidade);
printf("PIB per Capita: Carta 1 venceu: (%d)\n", venceuPIBperCapita);
printf("Super Poder: Carta 1 venceu: (%d)\n", venceuSuperPoder);

// Vamos criar uma logica para um vencedor e um derrotado, afinal ainda é um jogo.
// Aqui  usuario será o responsavel por calcular se venceu ou perdeu. 
printf(GREEN "\n==============================================================\n" RESET);
printf("ORIENTAÇÃO:\n");
printf("- Cada linha indica se a Carta 1 venceu (1) ou não (0).\n");
printf("- Some quantos números '1' aparecem.\n");
printf("- Se a Carta 1 tiver 4 ou mais, ela é a vencedora!\n");
printf("- Caso tenha menos de 4, a vencedora é a Carta 2.\n");
printf(GREEN "==============================================================\n" RESET);

printf(RED "Digite quem venceu (1 para Carta 1, 2 para Carta 2): " RESET);
scanf("%d", &cartaVencedor);

printf(GREEN "\nPARABÉNS:A Carta %d é vencedora!\n" RESET, cartaVencedor);

return 0;
}
