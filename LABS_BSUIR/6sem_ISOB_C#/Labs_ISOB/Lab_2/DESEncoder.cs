using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2
{
    public class DESEncoder
    {
        private int letterBitSize = 16;
        private static int chunkSize = 64;
        private BitArray primaryKey; //new BitArray(chunkSize);

        int[] startPermutation = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };
        int[] finalPermutation = { 40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25 };
        int[][][] sBoxes = { new int[][] {
                                new int[] {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
                                new int[] {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
                                new int[] {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
                                new int[] {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},

                            new int[][] { 
                                new int[] {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
                                new int[] {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
                                new int[] {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
                                new int[] {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},

                            new int[][] { 
                                new int[] {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
                                new int[] {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
                                new int[] {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
                                new int[] {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},

                            new int[][] { 
                                new int[] {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
                                new int[] {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
                                new int[] {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
                                new int[] {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},

                            new int[][] { 
                                new int[] {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
                                new int[] {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
                                new int[] {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
                                new int[] {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},

                            new int[][] {
                                new int[] {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
                                new int[] {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
                                new int[] {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
                                new int[] {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},

                            new int[][] { 
                                new int[] {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
                                new int[] {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
                                new int[] {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
                                new int[] {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},

                            new int[][] { 
                                new int[] {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
                                new int[] {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
                                new int[] {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
                                new int[] {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}
        };
        int[] KeyPermutationTable1 = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26,
                                 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52,
                                 44, 36,
                                 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30,
                                 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
        int[] KeyPermutationTable2 = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
                                 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
                                 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
                                 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
        int[] PPermutation = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18,
                          31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22,
                          11, 4, 25};
        int[] KeyShiftTable = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
        int[] ExtTable = new int[]
        {
            32, 1, 2, 3, 4, 5,
            4, 5, 6, 7, 8, 9,
            8, 9, 10, 11, 12, 13,
            12, 13, 14, 15, 16, 17,
            16, 17, 18, 19, 20, 21,
            20, 21, 22, 23, 24, 25,
            24, 25, 26, 27, 28, 29,
            28, 29, 30, 31, 32, 1
        };

        public DESEncoder(string key)
        {
            primaryKey = new BitArray(SubBits(new BitArray(Encoding.Unicode.GetBytes(key)), 0, Encoding.Unicode.GetBytes(key).Length * 8 > 64 ? 64 : Encoding.Unicode.GetBytes(key).Length * 8));

            primaryKey.Length = 64;
        }

        public void KeyShift(BitArray input, int step, int len)
        {
            int shift = KeyShiftTable[step];
            BitArray temp = new BitArray(shift);

            temp = SubBits(input, 0, shift);

            for(int i = 0; i < len - shift; i++) 
            {
                input[i] = input[i + shift];
            }

            for(int i = 0; i < shift; i++)
            {
                input[len - shift + i] = temp[i]; 
            }
        }

        /*public void KeyShift(BitArray input, int step)
        {
            int shift = KeyShiftTable[step];
            BitArray temp = new BitArray(shift);

            // Сохраняем последние shift битов в temp
            for (int i = 0; i < shift; i++)
            {
                temp[i] = input[input.Length - shift + i];
            }

            // Сдвигаем биты вправо
            for (int i = input.Length - 1; i >= shift; i--)
            {
                input[i] = input[i - shift];
            }

            // Перемещаем биты из temp в начало input
            for (int i = 0; i < shift; i++)
            {
                input[i] = temp[i];
            }
        }*/

        /*public void KeyShift(BitArray input, int step, int len)
        {
            int shift = KeyShiftTable[step];
            BitArray temp = new BitArray(shift);

            // Сохраняем последние shift битов в temp
            for (int i = 0; i < shift; i++)
            {
                temp[i] = input[len - shift + i];
            }

            // Сдвигаем биты вправо
            for (int i = len - 1; i >= shift; i--)
            {
                input[i] = input[i - shift];
            }

            // Перемещаем биты из temp в начало input
            for (int i = 0; i < shift; i++)
            {
                input[i] = temp[i];
            }
        }*/

        public string Encrypt(string input)
        {
            if(input.Length % (chunkSize / letterBitSize) != 0)
            {
                while(input.Length % (chunkSize / letterBitSize) != 0)
                {
                    input = input + '\x02';
                }
            }

            Encoding encoding = Encoding.Unicode;

            List<BitArray> result = new List<BitArray>();
            BitArray stringBits = new BitArray(Encoding.Unicode.GetBytes(input));
            List<BitArray> chunkArray = new List<BitArray>();
            string resultString = "";

            for(int i = 0; i < stringBits.Length; i++)
            {
                if (i % chunkSize == 0)
                {
                    chunkArray.Add(new BitArray(chunkSize));
                }

                chunkArray[i / chunkSize][i % chunkSize] = stringBits[i];
            }

            foreach (var chunk in chunkArray)
            {
                result.Add(EncryptBlock(chunk));
            }

            foreach (var chunk in result)
            {
                byte[] temp = new byte[8];
                chunk.CopyTo(temp, 0);

                resultString += Encoding.Unicode.GetString(temp);
            }

            return resultString;
        }

        public string Decrypt(string input)
        {
            Encoding encoding = Encoding.Unicode;

            List<BitArray> result = new List<BitArray>();
            BitArray stringBits = new BitArray(Encoding.Unicode.GetBytes(input));
            List<BitArray> chunkArray = new List<BitArray>();
            string resultString = "";

            for (int i = 0; i < stringBits.Length; i++)
            {
                if (i % chunkSize == 0)
                {
                    chunkArray.Add(new BitArray(chunkSize));
                }

                chunkArray[i / chunkSize][i % chunkSize] = stringBits[i];
            }

            foreach (var chunk in chunkArray)
            {
                result.Add(DecryptBlock(chunk));
            }

            foreach (var chunk in result)
            {
                byte[] temp = new byte[8];
                chunk.CopyTo(temp, 0);

                resultString += Encoding.Unicode.GetString(temp);
            }

            return resultString.Trim('\x02');
        }

        public List<BitArray> GetKeySet()
        {

            BitArray key = BitsPermutation(primaryKey, KeyPermutationTable1);
            List<BitArray> keyList = new List<BitArray>();
            BitArray c = SubBits(key, 0, key.Length / 2), d = SubBits(key, key.Length / 2, key.Length / 2);

            for(int i = 0; i < 16; i++) 
            {
                keyList.Add(BitsPermutation(MergeBitArrays(c, d, 28, 28), KeyPermutationTable2));
                
                KeyShift(c, i, 28);
                KeyShift(d, i, 28);
            }

            return keyList;
        }

        public BitArray EncryptBlock(BitArray block)
        {
            /*for (int i = 0, j = block.Length - 1; i < j; i++, j--)
            {
                bool temp = block[i];
                block[i] = block[j];
                block[j] = temp;
            }*/

            block = BitsPermutation(block, startPermutation);

            List<BitArray> keys = GetKeySet();
            BitArray left = SubBits(block, 0, block.Length / 2), right = SubBits(block, block.Length / 2, block.Length / 2);

            for (int i = 0; i < 16; i++)
            {
                BitArray left_old = new BitArray(left);

                left = new BitArray(right);

                right = Extension(right);

                right = right.Xor(keys[i]);

                right = Compression(right);
                right = BitsPermutation(right, PPermutation);

                right = right.Xor(left_old);
            }

            block = MergeBitArrays(right, left);
            block = BitsPermutation(block, finalPermutation);

            /*for (int i = 0, j = block.Length - 1; i < j; i++, j--)
            {
                bool temp = block[i];
                block[i] = block[j];
                block[j] = temp;
            }*/

            return block;
        }

        public BitArray DecryptBlock(BitArray block)
        {
            /*for (int i = 0, j = block.Length - 1; i < j; i++, j--)
            {
                bool temp = block[i];
                block[i] = block[j];
                block[j] = temp;
            }*/

            block = BitsPermutation(block, startPermutation);

            List<BitArray> keys = GetKeySet();
            BitArray left = SubBits(block, 0, block.Length / 2), right = SubBits(block, block.Length / 2, block.Length / 2);

            for (int i = 0; i < 16; i++)
            {
                BitArray left_old = new BitArray(left);

                left = new BitArray(right);

                right = Extension(right);

                right = right.Xor(keys[15 - i]);

                right = Compression(right);
                right = BitsPermutation(right, PPermutation);

                right = right.Xor(left_old);
            }

            block = MergeBitArrays(right, left);
            block = BitsPermutation(block, finalPermutation);

            /*for (int i = 0, j = block.Length - 1; i < j; i++, j--)
            {
                bool temp = block[i];
                block[i] = block[j];
                block[j] = temp;
            }*/

            return block;
        }

        public BitArray BitsPermutation(BitArray input, int[] permutationTable) 
        {
            BitArray outBits = new BitArray(permutationTable.Length);

            for(int i = 0; i < permutationTable.Length ; i++)
            {
                outBits[i] = input[permutationTable[i] - 1];
            }

            return outBits;
        }

        public BitArray Compression(BitArray input)
        {
            BitArray outBits = new BitArray(32);

            for(int i = 0; i < 8; i++)
            {
                BitArray tmp = new BitArray(new int[] { sBoxes[i][BitArrayToInt(MergeBitArrays(SubBits(input, i * 6, 1), SubBits(input, i * 6 + 5, 1), 1, 1))][BitArrayToInt(SubBits(input, i * 6 + 1, 4))] });

                for (int j = i * 4; j < (i + 1) * 4; j++)
                {
                    outBits[j] = tmp[j - 4 * i];
                }
            }

            return outBits;
        }

        public BitArray Extension(BitArray input)
        { 
            BitArray outBits = new BitArray(48);

            /*outBits[0] = input[31];
            outBits[47] = input[0];

            for(int i = 0; i < 8; i++)
            {
                if(i != 0) 
                {
                    outBits[i * 6] = input[i * 4 - 1];                
                }

                if(i != 7)
                {
                    outBits[i * 6 + 5] = input[(i + 1) * 4];
                }

                for(int j = 1; j < 5; j++)
                {
                    outBits[i * 6 + j] = input[i * 4 + j - 1];
                }
            }*/
            outBits = BitsPermutation(input, ExtTable);

            return outBits;
        }

        public BitArray SubBits(BitArray input, int start, int lenght) 
        {
            BitArray outBits = new BitArray(lenght);

            for(int i = start; i < start + lenght; i++)
            {
                outBits[i - start] = input[i];
            }

            return outBits;
        }

        public int BitArrayToInt(BitArray block)
        {
            var bits = new BitArray(block);

            /*for (int i = 0, j = bits.Length - 1; i < j; i++, j--)
            {
                bool temp = bits[i];
                bits[i] = bits[j];
                bits[j] = temp;
            }*/

            int result = 0;
            for (int i = 0; i < bits.Length; i++)
            {
                if (bits[i])
                {
                    result |= (1 << i);
                }
            }

            return result;
        }

        public BitArray Reverse(BitArray input, int len)
        {
            var bits = new BitArray(input);

            for (int i = 0, j = len - 1; i < j; i++, j--)
            {
                bool temp = bits[i];
                bits[i] = bits[j];
                bits[j] = temp;
            }

            return bits;
        }

        public BitArray MergeBitArrays(BitArray first, BitArray second) 
        {
            BitArray outBits = new BitArray(first.Length + second.Length);

            for(int i = 0; i < first.Length; i++)
            {
                outBits[i] = first[i];
            }

            for(int i = 0; i < second.Length; i++)
            {
                outBits[i + first.Length] = second[i];
            }

            return outBits;
        }

        public BitArray MergeBitArrays(BitArray first, BitArray second, int len1, int len2)
        {
            BitArray outBits = new BitArray(len1 + len2);

            for (int i = 0; i < len1; i++)
            {
                outBits[i] = first[i];
            }

            for (int i = 0; i < len2; i++)
            {
                outBits[i + len1] = second[i];
            }

            return outBits;
        }

        public static string BitArrayToString(BitArray bitArray)
        {
            // Создаем строку для хранения битов
            char[] bits = new char[bitArray.Length];

            // Проходимся по каждому элементу BitArray
            for (int i = 0; i < bitArray.Length; i++)
            {
                // Если бит равен true, ставим '1', иначе '0'
                bits[i] = bitArray[i] ? '1' : '0';
            }

            // Преобразуем массив символов в строку и возвращаем её
            return new string(bits);
        }
    }
}
