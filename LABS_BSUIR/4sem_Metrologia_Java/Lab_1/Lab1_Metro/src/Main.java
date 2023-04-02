import java.io.IOException;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        String path = "C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\4sem_Metrologia_Java" +
                "\\Lab_1\\TestProgram.txt";

        Map<String, Integer> operators = new TreeMap<>();
        Map<String, Integer> operands = new TreeMap<>();
        Map<String, Integer> onlyOperators = new TreeMap<>();

        Scanner sc = new Scanner(Paths.get(path));

        while (sc.hasNext())
        {
            String temp = sc.nextLine();

            Util.ariphmeticOperator(operators, temp);
        }

        sc.close();

        operators.forEach((key, value) -> {
            if(value != 0)
            {
                System.out.println(key + " : " + value);

                onlyOperators.put(key, value);
            }
        });

        sc = new Scanner(Paths.get(path));

        while (sc.hasNext())
        {
            String temp = sc.nextLine();

            Util.findOperands(temp, operands, onlyOperators);
        }

        sc.close();

        System.out.println("Operands:");

        operands.forEach((key, value) -> {
            System.out.println(key + " : " + value);
        });
    }
}