import java.util.HashMap;

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

    public static int wordOperatorCount(String source, String ch) // совпадение строки спереди может быть таб
    {
        int result = 0;
        int temp = 0;

        for(int i = 0; i < source.length(); i++)
        {
            if(source.charAt(i) == ch.charAt(temp) && (source.charAt(i - 1 - temp) == ' ' ||
                    source.charAt(i - 1 - temp) == '\t'))
            {
                temp++;

                if(temp == ch.length() && (source.charAt(i - temp) == ' ' || source.charAt(i - temp) == '\t')
                        && source.charAt(i + 1) == ' ')
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



    public static void ariphmeticOperator(HashMap<String, Integer> operators, String line)
    {
        if(line.contains("+"))
        {
            operators.put("+", (operators.get("+") == null ? 0 : operators.get("+")) + Util.CountOperator(line, "+"));
        }

        if(line.contains("-"))
        {
            operators.put("-", (operators.get("-") == null ? 0 : operators.get("-")) + Util.CountOperator(line, "-"));
        }

        if(line.contains("*"))
        {
            operators.put("*", (operators.get("*") == null ? 0 : operators.get("*")) + Util.CountOperator(line, "*"));
        }

        if(line.contains("/"))
        {
            operators.put("/", (operators.get("/") == null ? 0 : operators.get("/")) + Util.CountOperator(line, "/"));
        }

        if(line.contains("%"))
        {
            operators.put("%", (operators.get("%") == null ? 0 : operators.get("%")) + Util.CountOperator(line, "%"));
        }

        if(line.contains("<"))
        {
            operators.put("<", (operators.get("<") == null ? 0 : operators.get("<")) + Util.CountOperator(line, "<"));
        }

        if(line.contains(">"))
        {
            operators.put(">", (operators.get(">") == null ? 0 : operators.get(">")) + Util.CountOperator(line, ">"));
        }

        if(line.contains("="))
        {
            operators.put("=", (operators.get("=") == null ? 0 : operators.get("=")) + Util.CountOperator(line, "="));
        }

        if(line.contains("=="))
        {
            operators.put("==", (operators.get("==") == null ? 0 : operators.get("==")) + Util.CountOperator(line, "=="));
        }

        if(line.contains("!="))
        {
            operators.put("!=", (operators.get("!=") == null ? 0 : operators.get("!=")) + Util.CountOperator(line, "!="));
        }

        if(line.contains(">="))
        {
            operators.put(">=", (operators.get(">=") == null ? 0 : operators.get(">=")) + Util.CountOperator(line, ">="));
        }

        if(line.contains("<="))
        {
            operators.put("<=", (operators.get("<=") == null ? 0 : operators.get("<=")) + Util.CountOperator(line, "<="));
        }

        if(line.contains("&&"))
        {
            operators.put("&&", (operators.get("&&") == null ? 0 : operators.get("&&")) + Util.CountOperator(line, "&&"));
        }

        if(line.contains("||"))
        {
            operators.put("||", (operators.get("||") == null ? 0 : operators.get("||")) + Util.CountOperator(line, "||"));
        }

        if(line.contains("|"))
        {
            operators.put("|", (operators.get("|") == null ? 0 : operators.get("|")) + Util.CountOperator(line, "|"));
        }

        if(line.contains("&"))
        {
            operators.put("&", (operators.get("&") == null ? 0 : operators.get("&")) + Util.CountOperator(line, "&"));
        }

        if(line.contains("<<"))
        {
            operators.put("<<", (operators.get("<<") == null ? 0 : operators.get("<<")) + Util.CountOperator(line, "<<"));
        }

        if(line.contains(">>"))
        {
            operators.put(">>", (operators.get(">>") == null ? 0 : operators.get(">>")) + Util.CountOperator(line, ">>"));
        }

        if(line.contains("^"))
        {
            operators.put("^", (operators.get("^") == null ? 0 : operators.get("^")) + Util.CountOperator(line, "^"));
        }

        if(line.contains("+="))
        {
            operators.put("+=", (operators.get("+=") == null ? 0 : operators.get("+=")) + Util.CountOperator(line, "+="));
        }

        if(line.contains("-="))
        {
            operators.put("-=", (operators.get("-=") == null ? 0 : operators.get("-=")) + Util.CountOperator(line, "-="));
        }

        if(line.contains("/="))
        {
            operators.put("/=", (operators.get("/=") == null ? 0 : operators.get("/=")) + Util.CountOperator(line, "/="));
        }

        if(line.contains("*="))
        {
            operators.put("*=", (operators.get("*=") == null ? 0 : operators.get("*=")) + Util.CountOperator(line, "*="));
        }

        if(line.contains("%="))
        {
            operators.put("%=", (operators.get("%=") == null ? 0 : operators.get("%=")) + Util.CountOperator(line, "%="));
        }

        if(line.contains("&="))
        {
            operators.put("&=", (operators.get("&=") == null ? 0 : operators.get("&=")) + Util.CountOperator(line, "&="));
        }

        if(line.contains("|="))
        {
            operators.put("|=", (operators.get("|=") == null ? 0 : operators.get("|=")) + Util.CountOperator(line, "|="));
        }

        if(line.contains("^="))
        {
            operators.put("^=", (operators.get("^=") == null ? 0 : operators.get("^=")) + Util.CountOperator(line, "^="));
        }

        if(line.contains(">>="))
        {
            operators.put(">>=", (operators.get(">>=") == null ? 0 : operators.get(">>=")) + Util.CountOperator(line, ">>="));
        }

        if(line.contains("<<="))
        {
            operators.put("<<=", (operators.get("<<=") == null ? 0 : operators.get("<<=")) + Util.CountOperator(line, "<<="));
        }

        if(line.contains("if"))
        {
            operators.put("if...else", (operators.get("if...else") == null ? 0 :
                    operators.get("if...else")) + Util.wordOperatorCount(line, "if"));
        }

        if(line.contains("delete"))
        {
            operators.put("delete", (operators.get("delete") == null ? 0 :
                    operators.get("delete")) + Util.wordOperatorCount(line, "delete"));
        }

        if(line.contains("delete[]"))
        {
            operators.put("delete[]", (operators.get("delete[]") == null ? 0 :
                    operators.get("delete[]")) + Util.wordOperatorCount(line, "delete[]"));
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
                    operators.get("for")) + Util.wordOperatorCount(line, "for"));
        }

        if(line.contains("while"))
        {
            operators.put("while", (operators.get("while") == null ? 0 :
                    operators.get("while")) + Util.wordOperatorCount(line, "while"));
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

                temp = temp.substring(temp.indexOf("(") + 1, temp.length());
            }
        }
    }
}
