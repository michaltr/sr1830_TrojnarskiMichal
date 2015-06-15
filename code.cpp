    #include "stdio.h"
     
    float calcNewValue(int votes, int mandates)
    {
    return (votes*1.0) / (mandates + 1.0);
    }
     
    int main()
    {
    int mandates[100];
    int votes[100];
    float calcTab[100];
    float max;
    int groupCount, mandatesCount, i, j, maxInd;
     
    //get all data
    printf("Podaj liczbe partii (max. 100)\n");
    scanf("%d", &groupCount);
     
    printf("Podaj liczbe mandatow\n");  
    scanf("%d", &mandatesCount);
     
    for (i=0; i<groupCount; i++)
    {
    printf("Podaj liczbe glosow na partie %d\n", i+1);  
    scanf("%d", &votes[i]);  
    }
     
    //clear number of mandates
    for (i=0; i<groupCount; i++)
    {
    mandates[i] = 0;
    }
     
    //calculate mandates (d'Hondt)
    for (i=0; i<groupCount; i++)
    {
    calcTab[i] = votes[i];
    }
    for (i=0; i<mandatesCount; i++)
    {
    //find max
    max = -1;
    for (j=0; j<groupCount; j++)
    {
    if (max<calcTab[j])
    {
    max = calcTab[j];
    maxInd = j;
    }
    }
     
    //give mandate for party with max
    mandates[maxInd]++;
    calcTab[maxInd] = calcNewValue(votes[maxInd], mandates[maxInd]);
    }
     
    //present results
    for (i=0; i<groupCount; i++)
    {
    printf("Partia %d ma %d mandatow\n", i+1, mandates[i]);  
    }  
     
    return 0;
    }