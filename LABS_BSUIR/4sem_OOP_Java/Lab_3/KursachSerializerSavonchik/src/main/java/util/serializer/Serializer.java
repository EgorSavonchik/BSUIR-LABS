package util.serializer;

import com.google.gson.Gson;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
public class Serializer
{
    static public <T> void Write(List<T> obj, String path) throws IOException
    {
        Gson gson = new Gson();

        FileWriter fileWriter = new FileWriter(path);
        fileWriter.write(gson.toJson(obj));

        fileWriter.close();
    }

    static public <T> T Read(String path, Class<T> cl) throws IOException
    {
        Gson gson = new Gson();

        FileReader fileReader = new FileReader(path);
        Scanner sc = new Scanner(fileReader);
        T out = gson.fromJson(sc.nextLine(), cl);

        fileReader.close();
        sc.close();

        return out;
    }
}