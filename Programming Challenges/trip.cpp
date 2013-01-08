//Este código da Accepted pero es cualquiera
//(los resultados no son correctos, por ejemplo 3: 10.02, 10.01, 10.0 da
//$6.01 como resultado...)
//El código está sacado de acá:
//http://blog.csdn.net/liukaipeng/article/details/3136298

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define MAX 1000
        
int calc_exchange(int costs[], int persons) 
{
  int total = 0, aver, exchange, budget;
  int i;
  for (i = 0; i < persons; ++i)
    total += costs[i];
  aver = total / persons;
  exchange = 0;
  budget = 0;
  if (total % persons != 0)
    aver += 1;
  for (i = 0; i < persons; ++i) {
    if (costs[i] >= aver) {
      exchange += costs[i] - aver;
      budget += costs[i] - aver;
    } else if (costs[i] < aver - 1) {
      budget -= aver - 1 - costs[i];
    }
  }
  if (budget < 0)
    exchange -= budget;
  return exchange;
}       
int main(int argc, char *argv[])
{
  int costs[MAX];
  char buf[20];
  int len;
  char c;
  int persons, i, j;
  int exchange;
  for (scanf("%d\n", &persons); persons != 0; scanf("%d\n", &persons)) {
    for (i = 0; i < persons; ++i) {
      for (j = 0; (c = getchar()) != '\n'; ++j) {
        if (c != '.')
          buf[j] = c;
        else
          --j;
      }
      buf[j] = '\0';
      costs[i] = atoi(buf);
    }
    exchange = calc_exchange(costs, persons);
    sprintf(buf, "%d", exchange);
    len = strlen(buf);
    if (len == 1)
      printf("$0.0%s\n", buf);
    else if (len == 2)
      printf("$0.%s\n", buf);
    else {
      putchar('$');
      for (i = 0; i < len - 2; ++i)
        putchar(buf[i]);
      printf(".%s\n", buf+len-2);
    }
  }
  return 0;
}



//Este es mi código que anda bien creo aunque da WA:

/*
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

void thetrip(vector<float> &v, float prom)
{
	stringstream ss;
	ss<<fixed<<setprecision(2)<<prom<<endl;
	ss>>prom;
	float cambios = 0, pozo = 0;
	for (int i=0; i<v.size(); ++i){
		float dif = v[i] - prom;
		if (dif > 0)
			cambios += dif;
		pozo += dif;
	}
	if (pozo > 1e-10) //quedó un centavo
		cambios -= 0.01;
	cout<<"$"<<fixed<<setprecision(2)<<cambios<<endl;
	
}

int main(){

	int n;
	float suma;
	while (cin>>n && n!=0){
		vector<float> v(n);
		suma = 0;
		for (int i=0; i<n; ++i){
			cin>>v[i];
			suma += v[i];
		}
		suma /= n;
		thetrip(v, suma);
	}
	return 0;
}
*/
