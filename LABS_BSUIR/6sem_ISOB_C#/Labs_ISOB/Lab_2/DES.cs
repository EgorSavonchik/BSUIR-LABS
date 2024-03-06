using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2
{
    public static class DES
    {
        private const int sizeOfBlock = 128;

        private const int sizeOfChar = 16;

        private const int shiftKey = 2;

        private const int quantityOfRounds = 16;

        private static string[] Blocks { get; set; }

        public static string Decipher(string message, string key)
        {
            key = GetDecipherKey(message, key);
            message = StringToBinaryFormat(message);

            CutBinaryStringIntoBlocks(message);

            for (int j = 0; j < quantityOfRounds; j++)
            {
                for (int i = 0; i < Blocks.Length; i++)
                {
                    Blocks[i] = DecodeDES_One_Round(Blocks[i], key);
                }

                key = KeyToPrevRound(key);
            }

            string result = string.Concat(Blocks);
            return StringFromBinaryToNormalFormat(result).Trim('#');
        }

        public static string Encrypt(string message, string key)
        {
            message = StringToRightLength(message);

            CutStringIntoBlocks(message);

            key = CorrectKeyWord(key, message.Length / (2 * Blocks.Length));
            key = StringToBinaryFormat(key);

            for (int j = 0; j < quantityOfRounds; j++)
            {
                for (int i = 0; i < Blocks.Length; i++)
                {
                    Blocks[i] = EncodeDES_One_Round(Blocks[i], key);
                }

                key = KeyToNextRound(key);
            }

            string result = string.Concat(Blocks);
            return StringFromBinaryToNormalFormat(result);
        }

        /// <summary>
        /// Метод, доводящий строку до такого размера, 
        /// чтобы она делилась на sizeOfBlock.
        /// </summary>
        private static string StringToRightLength(string input)
        {
            while (((input.Length * sizeOfChar) % sizeOfBlock) != 0)
                input += "#";

            return input;
        }

        /// <summary>
        /// Метод, разбивающий строку в обычном 
        /// (символьном) формате на блоки.
        /// </summary>
        private static void CutStringIntoBlocks(string input)
        {
            Blocks = new string[(input.Length * sizeOfChar) / sizeOfBlock];

            int lengthOfBlock = input.Length / Blocks.Length;

            for (int i = 0; i < Blocks.Length; i++)
            {
                Blocks[i] = input.Substring(i * lengthOfBlock, lengthOfBlock);
                Blocks[i] = StringToBinaryFormat(Blocks[i]);
            }
        }

        /// <summary>
        /// Метод, разбивающий строку в двоичном формате на блоки.
        /// </summary>
        private static void CutBinaryStringIntoBlocks(string input)
        {
            Blocks = new string[input.Length / sizeOfBlock];

            int lengthOfBlock = input.Length / Blocks.Length;

            for (int i = 0; i < Blocks.Length; i++)
                Blocks[i] = input.Substring(i * lengthOfBlock, lengthOfBlock);
        }

        /// <summary>
        /// Метод, переводящий строку в двоичный формат.
        /// </summary>
        private static string StringToBinaryFormat(string input)
        {
            string output = string.Empty;

            for (int i = 0; i < input.Length; i++)
            {
                string char_binary = Convert.ToString(input[i], 2);

                while (char_binary.Length < sizeOfChar)
                    char_binary = "0" + char_binary;

                output += char_binary;
            }

            return output;
        }

        /// <summary>
        /// Метод, доводящий длину ключа до нужной длины.
        /// </summary>
        private static string CorrectKeyWord(string input, int lengthKey)
        {
            if (input.Length > lengthKey)
                input = input.Substring(0, lengthKey);
            else
                while (input.Length < lengthKey)
                    input = "0" + input;

            return input;
        }

        private static string EncodeDES_One_Round(string input, string key)
        {
            string L = input.Substring(0, input.Length / 2);
            string R = input.Substring(input.Length / 2, input.Length / 2);

            return R + XOR(L, F(R, key));
        }

        private static string DecodeDES_One_Round(string input, string key)
        {
            string L = input.Substring(0, input.Length / 2);
            string R = input.Substring(input.Length / 2, input.Length / 2);

            return XOR(F(L, key), R) + L;
        }

        private static string XOR(string s1, string s2)
        {
            string result = string.Empty;

            for (int i = 0; i < s1.Length; i++)
            {
                bool a = s1[i] == '1';
                bool b = s2[i] == '1';

                result += a ^ b ? "1" : "0";
            }
            return result;
        }

        /// <summary>
        /// Шифрующая функция f. 
        /// </summary>
        private static string F(string s1, string s2) => XOR(s1, s2);

        /// <summary>
        /// Вычисление ключа для следующего раунда шифрования DES. 
        /// Циклический сдвиг >> shiftKey.
        /// </summary>
        private static string KeyToNextRound(string key)
        {
            for (int i = 0; i < shiftKey; i++)
            {
                key = key[^1] + key;
                key = key.Remove(key.Length - 1);
            }

            return key;
        }

        /// <summary>
        /// Вычисление ключа для следующего раунда расшифровки DES. 
        /// Циклический сдвиг << shiftKey.
        /// </summary>
        private static string KeyToPrevRound(string key)
        {
            for (int i = 0; i < shiftKey; i++)
            {
                key += key[0];
                key = key.Remove(0, 1);
            }

            return key;
        }

        /// <summary>
        /// Метод, переводящий строку с двоичными данными в символьный формат.
        /// </summary>
        private static string StringFromBinaryToNormalFormat(string input)
        {
            string output = string.Empty;

            while (input.Length > 0)
            {
                string char_binary = input.Substring(0, sizeOfChar);
                input = input.Remove(0, sizeOfChar);

                int a = 0;
                int degree = char_binary.Length - 1;

                foreach (char c in char_binary)
                    a += Convert.ToInt32(c.ToString()) * (int)Math.Pow(2, degree--);

                output += (char)a;
            }

            return output;
        }

        /// <summary>
        /// Метод преобразующий ключ в обратный
        /// </summary>
        private static string GetDecipherKey(string message, string key)
        {
            message = StringToRightLength(message);

            CutStringIntoBlocks(message);

            key = CorrectKeyWord(key, message.Length / (2 * Blocks.Length));
            key = StringToBinaryFormat(key);

            for (int j = 0; j < quantityOfRounds; j++)
            {
                key = KeyToNextRound(key);
            }

            return KeyToPrevRound(key);
        }
    }
}
