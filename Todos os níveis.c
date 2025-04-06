#include <stdio.h>
#include <locale.h>

int main() {
	//setlocale(LC_ALL, "pt_BR.UTF-8"); // Permitir output com acento
	setlocale(LC_ALL, "Portuguese");
	
    // Variáveis para a primeira carta
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densiPop1;
    float pibPerCapta1;

    //  Pedir dados para a primeira carta
    printf("Digite a letra inicial do estado da primeira carta (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o código da primeira carta, composto da letra inicial do estado acrescido de um numero de 01 até 04(Ex: H01): ");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade da primeira carta: ");
    getchar();  // Consome o '\n' deixado pelo scanf anterior
    fgets(nomeCidade1, 50, stdin);
    printf("Digite a quantidade de habitantes da cidade da primeira carta: ");
    scanf("%d", &populacao1);
    printf("Digite a área da cidade da primeira carta (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB da cidade da primeira carta (em milhões de reais): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos da cidade da primeira carta: ");
    scanf("%d", &pontosTuristicos1);

    // Declaração das variáveis para a segunda carta
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densiPop2;
    float pibPerCapta2;

    // Entrada de dados para a segunda carta
    printf("\nDigite a letra inicial do estado da segunda carta (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o código da segunda carta, composto da letra inicial do estado acrescido de um numero de 01 até 04(Ex: B03): ");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade da segunda carta: ");
    getchar();
    fgets(nomeCidade2, 50, stdin);
    printf("Digite a quantidade de habitantes da cidade da segunda carta: ");
    scanf("%d", &populacao2);
    printf("Digite a área da cidade da segunda carta (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade da segunda carta (em milhões de reais): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos da cidade da segunda carta: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo densidade populacional e pib per capta da carta 1
    densiPop1 = populacao1 / area1;
    pibPerCapta1 = (pib1 * 1000000) / populacao1;

    // Cálculo densidade populacional e pib per capta da carta 2
    densiPop2 = populacao2 / area2;
    pibPerCapta2 = (pib2 * 1000000) / populacao2;

    // Cálculo do super poder
    float superPoder1, superPoder2;
    // OBS: Não vou miltiplicar a população por 1 milhão, tendo em vista que isto é indiferente para a comparação
    // entre as duas cartas.
    superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapta1 + 1/densiPop1;
    superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapta2 + 1/densiPop2;

// Exibição de informações nível novato e aventureiro
    // Exibição das informações da carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f milhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densiPop1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapta1);

    // Exibição das informações da carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f milhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densiPop2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapta2);


// Exibição de informações nível mestre
   // Comparação de cartas
    int resultadoPop = populacao1>populacao2;
    int resultadoArea = area1>area2;
    int resultadoPib = pib1>pib2;
    int resultadoPtTuristico = pontosTuristicos1>pontosTuristicos2;
    int resultadoDensiPop = densiPop1<densiPop2; // Densidade populacional vence o menor valor
    int resultadoPibPerCapta = pibPerCapta1>pibPerCapta2;
    int resultadoSuperPoder = superPoder1>superPoder2;

    printf("\nComparação de cartas (1 - carta 1 venceu, 0 - carta 2 venceu): \n");
    printf("População: %d\n", resultadoPop);
    printf("Área: %d\n", resultadoArea);
    printf("PIB: %d \n", resultadoPib);
    printf("Número de Pontos Turísticos: %d\n", resultadoPtTuristico);
    printf("Densidade Populacional: %d\n", resultadoDensiPop);
    printf("PIB per Capita: %d \n", resultadoPibPerCapta);
    printf("Super poder: %d\n", resultadoSuperPoder);

    return 0;
}