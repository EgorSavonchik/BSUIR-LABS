import java.io.IOException;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        HashMap<String, Integer> operators = new HashMap<>();

        Scanner sc = new Scanner(Paths.get("C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\4sem_Metrologia_Java" +
                "\\Lab_1\\TestProgram.txt"));

        while (sc.hasNext())
        {
            String temp = sc.nextLine();

            Util.ariphmeticOperator(operators, temp);
        }

        operators.forEach((key, value) -> {
            if(value != 0)
            {
                System.out.println(key + ":" + value);
            }
        });
    }
}