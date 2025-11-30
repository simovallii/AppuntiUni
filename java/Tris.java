
public class Tris {
	
	private int winner;
	private char matrix[][];

	
	private void inizialize() {
		winner = - 1;
		matrix = new char[3][3];
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
			matrix[i][j] = '-';
			}
		}
	}
	
	public Tris() {
		
		this.inizialize();
	}
	
	public void print() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				System.out.print(matrix[i][j] + " ");
				
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tris game = new Tris();
		game.print();
		
		
	}

}
