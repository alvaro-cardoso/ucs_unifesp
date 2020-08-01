package primos;

import java.util.*;

public class Contador {
	public static int quantidade = 0;

	public static class Concorrencia implements Runnable {
		
		int ini;
		int fim;
		int interval;
		int numPrimo;

		public void run() {
			int j, k;
			for (j = ini; j <= interval; j++) {
				numPrimo = 0;
				for (k = 1; k <= j; k++) {
					if (j % k == 0) {
						numPrimo++;
					}
				}
				if (numPrimo == 2) {
					quantidade++;
				}
			}
			if (interval == fim)
				System.out.println("O intervalo possui " + quantidade + " numero(s) primo(s).");
		}
		
		public Concorrencia(int i, int f, int inte) {
			this.ini = i;
			this.fim = f;
			this.interval = inte;
		}
	}

	public static void main(String[] args) {
		int i, ini, fim, numThreads, tam;
		Scanner in = new Scanner(System.in);

		System.out.println("Digite o numero de threads");
		System.out.print(">> ");
		numThreads = in.nextInt();
		System.out.println("Digite o inicio e o fim do intervalo ");
		System.out.print("Inicio: ");
		ini = in.nextInt();
		System.out.print("Fim: ");
		fim = in.nextInt();
		tam = fim - ini;

		for (i = 1; i <= numThreads; i++) {
			Thread newThread = new Thread(new Concorrencia(( (i-1) / numThreads) * (tam) + ini + 1, fim, (( i / numThreads)) * (tam) + ini));
			newThread.start();
		}
		in.close();
	}
}
