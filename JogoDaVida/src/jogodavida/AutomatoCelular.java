package jogodavida;

/**
 *
 * @author MarquinhoZ
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AutomatoCelular extends JPanel implements ActionListener {
    private final int LINHAS = 50;        // Número de linhas
    private final int COLUNAS = 50;       // Número de colunas
    private final int TAMANHO_CELULA = 10; // Tamanho de cada célula
    private final int DELAY = 100;        // Delay entre as gerações (em milissegundos)
    
    private boolean[][] gradeAtual = new boolean[LINHAS][COLUNAS];
    private boolean[][] proximaGrade = new boolean[LINHAS][COLUNAS];
    private Timer timer;

    public AutomatoCelular() {
        setPreferredSize(new Dimension(LINHAS * TAMANHO_CELULA, COLUNAS * TAMANHO_CELULA));
        setBackground(Color.BLACK);
        
        // Inicializar a simulação com algumas células vivas
        gradeAtual[25][24] = true;
        gradeAtual[25][25] = true;
        gradeAtual[25][26] = true;

        timer = new Timer(DELAY, this);
        timer.start();  // Iniciar a simulação
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                if (gradeAtual[i][j]) {
                    g.setColor(Color.WHITE);
                } else {
                    g.setColor(Color.BLACK);
                }
                g.fillRect(j * TAMANHO_CELULA, i * TAMANHO_CELULA, TAMANHO_CELULA, TAMANHO_CELULA);
            }
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        atualizarGeracao();
        repaint();  // Re-desenhar a interface gráfica
    }

    private void atualizarGeracao() {
        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                int vizinhos = contarVizinhosVivos(i, j);
                if (gradeAtual[i][j]) {
                    // Regra do Jogo da Vida: Célula viva com 2 ou 3 vizinhos continua viva
                    proximaGrade[i][j] = (vizinhos == 2 || vizinhos == 3);
                } else {
                    // Regra do Jogo da Vida: Célula morta com exatamente 3 vizinhos vive
                    proximaGrade[i][j] = (vizinhos == 3);
                }
            }
        }
        
        // Copiar a próxima geração para a grade atual
        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                gradeAtual[i][j] = proximaGrade[i][j];
            }
        }
    }

    private int contarVizinhosVivos(int x, int y) {
        int vizinhos = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;  // Ignorar a própria célula
                }
                int linha = (x + i + LINHAS) % LINHAS;
                int coluna = (y + j + COLUNAS) % COLUNAS;
                if (gradeAtual[linha][coluna]) {
                    vizinhos++;
                }
            }
        }
        return vizinhos;
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Simulação de Autômatos Celulares");
        AutomatoCelular simulador = new AutomatoCelular();
        frame.add(simulador);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
