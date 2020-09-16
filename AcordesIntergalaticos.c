#include <stdio.h>

int main()
{
    int n, q, a, b;
    scanf("%d %d", &n, &q);
    
    if (n < 2 || n > 100000 || q < 1 || q > 100000)
        return 0;

    int i = 0, p[n];
    
    for (int i = 0; i < n; i++)
        p[i] = 1;
        
    while (i < q) {
        
        // Conferindo acordes
        scanf("%d %d", &a, &b);
        if (a < 0 || a > n || b < 0 || b > n || a > b)
            return 0;
            
        // Achando intervalo do acorde
        int inter = b - a;
        inter++;
        int pt[inter][2];
        
        for(int j = a; j <= b; j++) {
            pt[j-a][0] = p[j];
            pt[j-a][1] = 0;
        }
        
        // Conferindo repetições
        int nota, rep = 0;
        
        for (int j = 0; j < inter; j++) {
            for (int k = 0; k < inter; k++) {
                if (pt[j][0] == pt[k][0])
                    pt[j][1]++;
            }
            
            if (pt[j][1] > rep)
                rep = pt[j][1];
        }
        
        // Conferindo diferentes repetições
        int maior = 0;
        
        for (int j = 0; j < inter; j++) {
            if (pt[j][1] == rep && pt[j][0] > maior)
                maior = pt[j][0];
        }
        
        // Ajustando novo piano
        for (int j = a; j <= b; j++)
            p[j] = (p[j]+maior)%9;
        
  
        i++;
        
    }
    
    for (int i = 0; i < n; i++)
        printf("%d\n", p[i]);

    return 0;
}
