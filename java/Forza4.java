import java.util.Scanner;

public class Forza4 {
	
	private char matrix[][];
	private int winner;
	
	public Forza4() {
		winner = -1;
		matrix = new char[4][4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrix[i][j] = '-';
			}
		}
	}
	
	public boolean isFull() {
		
		return (matrix[0][1] == 'X' || matrix[0][1] == 'O') &&(matrix[0][2] == 'X' || matrix[0][2] == 'O') &&(matrix[0][3] == 'X' || matrix[0][3] == 'O' )&&(matrix[0][0] == 'X' || matrix[0][0] == 'O');
		
	}
	public boolean someoneWon() {
		if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X' && matrix[0][3] == 'X' ) {
			return true;
		}else if(matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O' && matrix[0][3] == 'O' ) {
			return true;
		}else if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X' && matrix[1][3] == 'X' ) {
			return true;
		}else if(matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O' && matrix[1][3] == 'O' ) {
			return true;
		}else if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X' && matrix[2][3] == 'X' ) {
			return true;
		}else if(matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O' && matrix[2][3] == 'O' ) {
			return true;
		}else if (matrix[3][0] == 'X' && matrix[3][1] == 'X' && matrix[3][2] == 'X' && matrix[3][3] == 'X' ) {
			return true;
		}else if(matrix[3][0] == 'O' && matrix[3][1] == 'O' && matrix[3][2] == 'O' && matrix[3][3] == 'O' ) {
			return true;
		}else if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X' && matrix[3][3] == 'X' ) {
			return true;
		}else if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O' && matrix[3][3] == 'O' ) {
			return true;
		}
		else if (matrix[3][0] == 'X' && matrix[2][1] == 'X' && matrix[1][2] == 'X' && matrix[0][3] == 'X' ) {
			return true;
		}else if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O' && matrix[3][3] == 'O' ) {
			return true;
		}else if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X' && matrix[3][0] == 'X' ) {
			return true;
		}else if(matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O' && matrix[3][0] == 'O' ) {
			return true;
		}else if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X' && matrix[3][1] == 'X' ) {
			return true;
		}else if(matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O' && matrix[3][1] == 'O' ) {
			return true;
		}else if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X' && matrix[3][2] == 'X' ) {
			return true;
		}else if(matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O' && matrix[3][2] == 'O' ) {
			return true;
		}else if (matrix[0][3] == 'X' && matrix[1][3] == 'X' && matrix[2][3] == 'X' && matrix[3][3] == 'X' ) {
			return true;
		}else if(matrix[0][3] == 'O' && matrix[1][3] == 'O' && matrix[2][3] == 'O' && matrix[3][3] == 'O' ) {
			return true;
		}
		return false;
	}
	private boolean rigaFull(int col) {
		return matrix[0][col] == 'X' || matrix[0][col] == 'O';
	}
	public boolean movePlayer1(int col) {
		
		if (col < 0 && col > 3) {
			System.err.println("valore errato");
			return false;
		}else if (rigaFull(col))
			{
			System.err.println("riga piena");
			return false;
			}
			else {
			
			
			for (int i = 3; i >= 0; i--) {
				if(matrix[i][col] == '-') {
					matrix[i][col] = 'X';
					
					if (someoneWon()) {
						winner = 1;
					}
					return true;
				}
				
			
			}
			
			return false;
		}
	}
	
public boolean movePlayer2(int col) {
		
		if (col < 0 && col > 3) {
			System.err.println("tabella piena");
			return false;
		}else if (rigaFull(col))
			{
			System.err.println("riga piena");
			return false;
			}
			else {
			
			
			for (int i = 3; i >= 0; i--) {
				if(matrix[i][col] == '-') {
					matrix[i][col] = 'O';
					return true;
				}
				if (someoneWon()) {
					winner = 0;
				}
				
			}
			
			return false;
		}
	}
	public void print() {
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}
	
public static void main(String[] args) {
	
	Scanner sc = new Scanner(System.in);
	Forza4 game = new Forza4();
	
	
	boolean player = false;
	
	
	do {
		game.print();
		int col;
		
		col = sc.nextInt();
		
		
		if (!player) {
			
			
			if (!game.movePlayer1(col)) {
				
				System.err.println("mossa invalida");
			}
		}else {
			

			if (!game.movePlayer2(col)) {
				
				System.err.println("mossa invalida");
			}
		}
		
		player = !player;
		
	}while(!game.isFull() && !game.someoneWon());
	
	game.print();
	if (game.winner == 1) {
		
		System.out.println("Il vincitore è il giocatore 1."  );
		
	}else if (game.winner == 2) {
		
		System.out.println("Il vincitore è il giocatore 2.");
		 
	}else if (game.isFull()) {
		
		System.out.println("Patta!");
	}
	sc.close();			
}

}

