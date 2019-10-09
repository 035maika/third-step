#include<stdio.h>
#include<math.h>
#define NUM 20

struct students{
	double sc;
	double eng;
};

int sum(int score[NUM]){
	int sum = 0;
	for(int i=0; i<NUM; i++){
		sum += score[i];
	}
	return sum;
}

double ave(int sum){
	return sum / NUM;
}

double std(int score[NUM], double ave){
	double var = 0.0;
	for(int i=0; i<NUM; i++){
		var += (score[i]-ave) * (score[i]-ave);
	}
	return sqrt(var / NUM);
}

double sts(int score, double ave, double std){
	double sts = 0.0;
	sts = 50 + (score - ave)/std * 10;
	return sts;
}
 
int main(){

	int Sscore[NUM] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70};
	int Escore[NUM] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};

	struct students stu[NUM];
	int Ssum = 0, Esum = 0;
	double Save = 0.0, Eave = 0.0;
	double Sstd = 0.0, Estd = 0.0;
	double Ssts = 0.0, Ests = 0.0;
	int Sdesc[NUM] = {0};
	int Edesc[NUM] = {0};
	int i, j, tmp;
	Ssum = sum(Sscore);
	Esum = sum(Escore);
	Save = ave(Ssum);
	Eave = ave(Esum);
	Sstd = std(Sscore, Save);
	Estd = std(Escore, Eave);

	printf("○理科\n");
	printf("平均: %lf\n", Save);
	printf("標準偏差: %lf\n", Sstd);
	printf("合計点: %d\n", Ssum);

	printf("○英語\n");
	printf("平均: %lf\n", Eave);
	printf("標準偏差: %lf\n", Estd);
	printf("合計点: %d\n", Esum);

	for(int i=0; i<NUM; i++){
		stu[i].sc = sts(Sscore[i], Save, Sstd);
		stu[i].eng = sts(Escore[i], Eave, Estd);
		printf("生徒%d	理科:%lf	英語:%lf\n", i+1, stu[i].sc, stu[i].eng);
	}

	for(int i=0; i<NUM; i++){
		for(j=i+1; j<NUM; j++){
			if(Sscore[i] < Sscore[j]){
				tmp = Sscore[i];
				Sscore[i] = Sscore[j];
				Sscore[j] = tmp;
			}
			 if(Escore[i] < Escore[j]){
                                tmp = Escore[i];
                                Escore[i] = Escore[j];
                                Escore[j] = tmp;
                        }
		}
	}

	printf("理科\n");
	for(int i=0; i<NUM; i++){
                printf("%d\n", Sscore[i]);
	}

	printf("英語\n");
	for(int i=0; i<NUM; i++){
		printf("%d\n", Escore[i]);
	}

	return 0;
}
