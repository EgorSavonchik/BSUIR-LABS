import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Util
{
    public static int CountOperator(String source, String ch) // совпадение строки + два пробела по бокам
    {
        int result = 0;
        int temp = 0;

        for(int i = 0; i < source.length(); i++)
        {
            if(source.charAt(i) == ch.charAt(temp) && source.charAt(i - 1 - temp) == ' ')
            {
                temp++;

                if(temp == ch.length() && source.charAt(i - temp) == ' ' && source.charAt(i + 1) == ' ')
                {
                    result++;
                    temp = 0;
                }

                if(temp == ch.length())
                {
                    temp = 0;
                }
            }
            else
            {
                temp = 0;
            }
        }

        return result;
    }

    public static void ariphmeticOperator(Map<String, Integer> operators, String line)
    {
        String[] signatures = {"+", "-", "*", "/", "%", "<", ">", "=", "==", "!=", ">=", "<=", "&&", "||", "|", "&", "<<", ">>",
            "^", "+=", "-=", "*=", "/=", "&=", "%=", "|=", "^=", ">>=", "<<="};

        if(line.length() != 0 && line.charAt(0) == '#')
        {
            return;
        }

        for(String sign : signatures)
        {
            if(line.contains(sign))
            {
                operators.put(sign, (operators.get(sign) == null ? 0 : operators.get(sign)) + Util.CountOperator(line, sign));
            }
        }

        for(int i = 0; i < line.length(); i++)
        {
            int temp = 0;

            if(line.charAt(i) == '*' && line.charAt(i - 1) != ' ')
            {
                while(line.charAt(i) == '*')
                {
                    i++;
                    temp++;
                }
            }

            if(temp != 0)
            {
                operators.put("ptr" + "*".repeat(temp), (operators.get("ptr" + "*".repeat(temp)) == null ? 0 :
                        operators.get("ptr" + "*".repeat(temp))) + 1);
            }
        }

        if(line.contains("if"))
        {
            operators.put("if...else", (operators.get("if...else") == null ? 0 :
                    operators.get("if...else")) + Util.CountOperator(line, "if"));
        }

        if(line.contains("delete"))
        {
            operators.put("delete", (operators.get("delete") == null ? 0 :
                    operators.get("delete")) + Util.CountOperator(line, "delete"));
        }

        if(line.contains("delete[]"))
        {
            operators.put("delete[]", (operators.get("delete[]") == null ? 0 :
                    operators.get("delete[]")) + Util.CountOperator(line, "delete[]"));
        }

        if(line.contains("return"))
        {
            operators.put("return", (operators.get("return") == null ? 0 : operators.get("return")) + 1);
        }

        if(line.contains("break"))
        {
            operators.put("break", (operators.get("break") == null ? 0 : operators.get("break")) + 1);
        }

        if(line.contains("continue"))
        {
            operators.put("continue", (operators.get("continue") == null ? 0 : operators.get("continue")) + 1);
        }

        if(line.contains("new"))
        {
            operators.put("new", (operators.get("new") == null ? 0 :
                    operators.get("new")) + Util.CountOperator(line, "new"));
        }

        if(line.contains("for"))
        {
            operators.put("for", (operators.get("for") == null ? 0 :
                    operators.get("for")) + Util.CountOperator(line, "for"));
        }

        if(line.contains("while"))
        {
            operators.put("while", (operators.get("while") == null ? 0 :
                    operators.get("while")) + Util.CountOperator(line, "while"));
        }

        if(line.contains(", "))
        {
            operators.put(",", (operators.get(",") == null ? 0 :
                    operators.get(",")) + (line.length() - line.replace(", ", " ").length()));
        }

        if(line.contains("::"))
        {
            operators.put("::", (operators.get("::") == null ? 0 :
                    operators.get("::")) + (line.length() - line.replace("::", " ").length()));
        }

        if(line.contains("!"))
        {
            operators.put("!", (operators.get("!") == null ? 0 : operators.get("!")) +
                    Math.toIntExact(line.replace("!=", "").chars().filter(ch ->  ch == '!').count()));
        }

        if(line.contains("(") && (line.charAt(line.indexOf("(") - 1) != ' '  && line.charAt(line.indexOf("(") - 1) != '\t'))
        {
            String temp = line;

            while(temp.contains("("))
            {
                String func = "";

                for(int i = temp.indexOf("(") - 1; i >= 0; i--)
                {
                    if(temp.charAt(i) == ' ' || temp.charAt(i) == '\t')
                    {
                        break;
                    }

                    func = temp.charAt(i) + func;
                }

                operators.put(func + "()", (operators.get(func + "()") == null ? 0 : operators.get(func + "()")) + 1);

                temp = temp.substring(temp.indexOf("(") + 1);
            }
        }

        operators.put("[]", (operators.get("[]") == null ? 0 : operators.get("[]")) +
                Math.toIntExact(line.replace("delete[]", "").chars().filter(ch ->  ch == '[').count()));
    }

    public static void findOperands(String line, Map<String, Integer> operands, Map<String, Integer> onlyOperators)
    {
        if(line.length() != 0 && line.charAt(0) == '#')
        {
            return;
        }

        String[] forDelete = {"{", "}", "(", ")", "[", "]", ";", "if", "else", "delete"};
        String[] types = {"int", "double", "char", "bool"};

        for(String str : forDelete)
        {
            line = line.replace(str, " ");
        }

        if(line.contains("std::"))
        {
            for(int i = 0; i < line.length() - 5; i++)
            {
                if(line.substring(i, i + 5).equals("std::"))
                {
                    for(int j = i; j < line.length(); j++)
                    {
                        if(line.charAt(j) == ' ')
                        {
                            line = line.replace(line.substring(i, j), "");

                            break;
                        }
                    }
                }
            }
        }

        for(String key : onlyOperators.keySet())
        {
            if(key.contains("("))
            {
                key = key.substring(0, key.length() - 2);
            }

            line = line.replace(key, " ");
        }

        for(String str : types)
        {
            line = line.replace(str, " ");
        }

        if(line.contains("\""))
        {
            String tempStr;

            for (int i = 0; i < line.length(); i++)
            {
                i = line.indexOf("\"");

                if(i == -1)
                {
                    break;
                }

                tempStr = line.substring(i, line.indexOf("\"", i + 1) + 1);

                operands.put(tempStr, (operands.get(tempStr) == null ? 0 : operands.get(tempStr)) + 1);
                line = line.replace(tempStr, " ");
            }
        }

        Arrays.stream(line.split(" ")).forEach(str ->
        {
            if (str == "")
            {
                return;
            }

            operands.put(str, (operands.get(str) == null ? 0 : operands.get(str)) + 1);
        });

        //System.out.println(line);
    }
}
