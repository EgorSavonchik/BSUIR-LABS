using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Lab_2
{
    public class EncryptionUtils
    {

        private static int[] PC1 =
                {
                    57, 49, 41, 33, 25, 17, 9,
                    1, 58, 50, 42, 34, 26, 18,
                    10, 2, 59, 51, 43, 35, 27,
                    19, 11, 3, 60, 52, 44, 36,
                    63, 55, 47, 39, 31, 23, 15,
                    7, 62, 54, 46, 38, 30, 22,
                    14, 6, 61, 53, 45, 37, 29,
                    21, 13, 5, 28, 20, 12, 4
            };

        // First index is garbage value, loops operating on this should start with index = 1
        private static int[] KEY_SHIFTS = {
            0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
    };

        private static int[] PC2 = {
            14, 17, 11, 24, 1, 5,
            3, 28, 15, 6, 21, 10,
            23, 19, 12, 4, 26, 8,
            16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32
    };


        private static int[][] s1 = {
            new int [] {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
            new int [] {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
            new int [] {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
            new int [] {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    };

        private static int[][] s2 = {
            new int [] {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
            new int [] {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
            new int [] {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
            new int [] {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    };

        private static int[][] s3 = {
            new int [] {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
            new int [] {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
            new int [] {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
            new int [] {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    };

        private static int[][] s4 = {
            new int [] {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
            new int [] {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
            new int [] {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
            new int [] {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    };

        private static int[][] s5 = {
            new int [] {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
            new int [] {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
            new int [] {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
            new int [] {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    };

        private static int[][] s6 = {
            new int [] {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
            new int [] {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
            new int [] {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
            new int [] {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
    };

        private static int[][] s7 = {
            new int [] {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
            new int [] {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
            new int [] {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
            new int [] {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    };

        private static int[][] s8 = {
            new int [] {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
            new int [] {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
            new int [] {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
            new int [] {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
    };

        private static int[][][] s = { s1, s2, s3, s4, s5, s6, s7, s8 };

        private static int[] g = {
            32, 1, 2, 3, 4, 5,
            4, 5, 6, 7, 8, 9,
            8, 9, 10, 11, 12, 13,
            12, 13, 14, 15, 16, 17,
            16, 17, 18, 19, 20, 21,
            20, 21, 22, 23, 24, 25,
            24, 25, 26, 27, 28, 29,
            28, 29, 30, 31, 32, 1
    };


        static int[] p = {
            16, 7, 20, 21,
            29, 12, 28, 17,
            1, 15, 23, 26,
            5, 18, 31, 10,
            2, 8, 24, 14,
            32, 27, 3, 9,
            19, 13, 30, 6,
            22, 11, 4, 25
    };

        private static int[] IP = {
            58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17, 9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7
    };

        static int[] IPi = {
            40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41, 9, 49, 17, 57, 25
    };

        private static long[] K = new long[17];

        private static String binToHex(String bin)
        {
            BigInteger b = new BigInteger(bin, 2);
            return b.ToString(16);
        }

        private static String hexToBin(String hex)
        {
            BigInteger b = new BigInteger(hex, 16);
            return b.ToString(2);
        }

        private static String binToutValF(String bin)
        {
            byte[] ciphertextBytes = new byte[bin.Length / 8];
            String ciphertext;
            for (int j = 0; j < ciphertextBytes.Length; j++)
            {
                String temp = bin.ToString().Substring(0, 8);
                byte b = (byte)Convert.ToInt32(temp, 2);
                ciphertextBytes[j] = b;
                bin = bin.ToString().Substring(8);
            }

            ciphertext = Encoding.UTF8.GetString(ciphertextBytes);
            return ciphertext.Trim();
        }

        private static String utfToBin(String utf)
        {
            byte[] bytes;
            bytes = Encoding.UTF8.GetBytes(utf);

            StringBuilder bin = new StringBuilder();
            foreach (int current in bytes)
            {
                int value = current;
                for (int j = 0; j < 8; j++)
                {
                    bin.Append((value & 128) == 0 ? 0 : 1);
                    value <<= 1;
                }
            }
            return bin.ToString();
        }

        public static byte[] encrypt(byte[] data, String key)
        {
            String plaintext = utfToBin(Encoding.UTF8.GetString(data));

            buildKeySchedule(hash(key));

            StringBuilder binPlaintext = new StringBuilder(plaintext);

            // Add padding if necessary
            int remainder = binPlaintext.Length % 64;
            if (remainder != 0)
            {
                for (int i = 0; i < (64 - remainder); i++)
                    binPlaintext.Insert(0, "0");
            }

            // Separate binary plaintext into blocks
            String[] binPlaintextBlocks = new String[binPlaintext.Length / 64];
            int offset = 0;
            for (int i = 0; i < binPlaintextBlocks.Length; i++)
            {
                binPlaintextBlocks[i] = binPlaintext.ToString().Substring(offset, offset + 64);
                offset += 64;
            }

            String[] binCiphertextBlocks = new String[binPlaintext.Length / 64];

            // Encrypt the blocks
            for (int i = 0; i < binCiphertextBlocks.Length; i++)
                binCiphertextBlocks[i] = encryptBlock(binPlaintextBlocks[i]);



            // Build the ciphertext binary string from the blocks
            // Build the ciphertext binary string from the blocks
            StringBuilder binCiphertext = new StringBuilder();
            for (int i = 0; i < binCiphertextBlocks.Length; i++)
                binCiphertext.Append(binCiphertextBlocks[i]);

            // Destroy key schedule
            Arrays.fill(K, 0);

            return binToHex(Encoding.UTF8.GetBytes(binCiphertext.ToString()));
        }

        public static String decrypt(byte[] data, String key)
        {
            String plaintext = hexToBin(new String(data));

            buildKeySchedule(hash(key));

            StringBuilder binPlaintext;

            binPlaintext = new StringBuilder(plaintext);

            // Add padding if necessary
            int remainder = binPlaintext.Length % 64;
            if (remainder != 0)
            {
                for (int i = 0; i < (64 - remainder); i++)
                    binPlaintext.Insert(0, "0");
            }

            // Separate binary plaintext into blocks
            String[] binPlaintextBlocks = new String[binPlaintext.Length / 64];
            int offset = 0;
            for (int i = 0; i < binPlaintextBlocks.Length; i++)
            {
                binPlaintextBlocks[i] = binPlaintext.ToString().Substring(offset, offset + 64);
                offset += 64;
            }

            String[] binCiphertextBlocks = new String[binPlaintext.Length / 64];

            // Encrypt the blocks
            for (int i = 0; i < binCiphertextBlocks.Length; i++)
            {

                binCiphertextBlocks[i] = decryptBlock(binPlaintextBlocks[i]);

            }

            // Build the ciphertext binary string from the blocks
            StringBuilder binCiphertext = new StringBuilder();
            foreach (String binCiphertextBlock in binCiphertextBlocks)
                binCiphertext.Append(binCiphertextBlock);

            // Destroy key schedule
            Arrays.fill(K, 0);

            return binToutValF(binCiphertext.ToString());
        }

        public static String encryptBlock(String plaintextBlock)
        {
            int Length = plaintextBlock.Length;


            //Initial permutation
            StringBuilder outVal = new StringBuilder();
            foreach (int j in IP)
            {
                outVal.Append(plaintextBlock[j - 1]);
            }

            String mL = outVal.ToString().Substring(0, 32);
            String mR = outVal.ToString().Substring(32);

            for (int i = 0; i < 16; i++)
            {

                // 48-bit current key
                StringBuilder curKey = new StringBuilder(Convert.ToString(K[i + 1], 2));
                while (curKey.Length < 48)
                    curKey.Insert(0, "0");

                // Get 32-bit result from f with m1 and ki
                String fResult = func(mR, curKey.ToString());

                // XOR m0 and f
                long f = Convert.ToInt64(fResult, 2);
                long cmL = Convert.ToInt64(mL, 2);

                long m2 = cmL ^ f;
                StringBuilder m2String = new StringBuilder(Convert.ToString(m2, 2));

                while (m2String.Length < 32)
                    m2String.Insert(0, "0");

                mL = mR;
                mR = m2String.ToString();
            }

            String in1 = mR + mL;
            StringBuilder outValput = new StringBuilder();
            foreach (int j in IPi)
            {
                outValput.Append(in1[j - 1]);
            }

            return outValput.ToString();
        }

        public static String decryptBlock(String plaintextBlock)
        {
            int Length = plaintextBlock.Length;


            //Initial permutation
            StringBuilder outVal = new StringBuilder();
            foreach (int j in IP)
            {
                outVal.Append(plaintextBlock[j - 1]);
            }

            String mL = outVal.ToString().Substring(0, 32);
            String mR = outVal.ToString().Substring(32);

            for (int i = 16; i > 0; i--)
            {

                // 48-bit current key
                StringBuilder curKey = new StringBuilder(Convert.ToString(K[i]), 2);
                while (curKey.Length < 48)
                    curKey.Insert(0, "0");

                // Get 32-bit result from f with m1 and ki
                String fResult = func(mR, curKey.ToString());

                // XOR m0 and f
                long f = Convert.ToInt64(fResult, 2);
                long cmL = Convert.ToInt64(mL, 2);

                long m2 = cmL ^ f;
                StringBuilder m2String = new StringBuilder(Convert.ToString(m2, 2));

                while (m2String.Length < 32)
                    m2String.Insert(0, "0");

                mL = mR;
                mR = m2String.ToString();
            }

            String in1 = mR + mL;
            StringBuilder outValput = new StringBuilder();
            foreach (int j in IPi)
            {
                outValput.Append(in1[j - 1]);
            }

            return outValput.ToString();
        }

        public static long hash(String string1)
        {
            long h = 1125899906842597L; // prime
            int len = string1.Length;

            for (int i = 0; i < len; i++)
            {
                h = 31 * h + string1[i];
            }
            return h;
        }

        public static void buildKeySchedule(long key)
        {
            // Convert long value to 64bit binary string
            StringBuilder binKey = new StringBuilder(Convert.ToString(key, 2));

            // Add leading zeros if not at key Length for ease of computations
            while (binKey.Length < 64)
                binKey.Insert(0, "0");

            // For the 56-bit permuted key
            StringBuilder binKey_PC1 = new StringBuilder();

            // Apply Permuted Choice 1 (64 -> 56 bit)
            foreach (int k in PC1)
                binKey_PC1.Append(binKey[k - 1]);

            String sL, sR;
            int iL, iR;

            // Split permuted string in half | 56/2 = 28
            sL = binKey_PC1.ToString().ToString().Substring(0, 28);
            sR = binKey_PC1.ToString().Substring(28);

            // Parse binary strings into integers for shifting
            iL = Convert.ToInt32(sL, 2);
            iR = Convert.ToInt32(sR, 2);

            // Build the keys (Start at index 1)
            for (int i = 1; i < K.Length; i++)
            {

                // Perform left shifts according to key shift array
                iL = Integer.rotateLeft(iL, KEY_SHIFTS[i]);
                iR = Integer.rotateLeft(iR, KEY_SHIFTS[i]);

                StringBuilder binKey_PC2 = mergeTwoHalves(iL, iR);

                // Set the 48-bit key
                K[i] = Convert.ToInt64(binKey_PC2.ToString(), 2);
            }
        }

        private static StringBuilder mergeTwoHalves(long iL, int iR)
        {
            long merged = (iL << 28) + iR;

            StringBuilder sMerged = new StringBuilder(Convert.ToString(merged, 2));

            // Fix Length if leading zeros absent
            while (sMerged.Length < 56)
                sMerged.Insert(0, "0");

            StringBuilder binKey_PC2 = new StringBuilder();

            // Apply Permuted Choice 2 (56 -> 48 bit)
            foreach (int k in PC2)
                binKey_PC2.Append(sMerged[k - 1]);
            return binKey_PC2;
        }

        public static String func(String mi, String key)
        {
            // Expansion function g (named E in fips pub 46)
            StringBuilder gMi = new StringBuilder();
            foreach (int value in g)
            {
                gMi.Append(mi[value - 1]);
            }

            long m = Convert.ToInt64(gMi.ToString(), 2);
            long k = Convert.ToInt64(key, 2);

            // XOR expanded message block and key block (48 bits)
            long result = m ^ k;

            StringBuilder bin = new StringBuilder(Convert.ToString(result, 2));
            // Making sure the string is 48 bits
            while (bin.Length < 48)
            {
                bin.Insert(0, "0");
            }

            // Split into eight 6-bit strings
            String[] sin = new String[8];
            for (int i = 0; i < 8; i++)
            {
                sin[i] = bin.ToString().Substring(0, 6);
                bin = new StringBuilder(bin.ToString().Substring(6));
            }

            // Do S-Box calculations
            String[] outValput = new String[8];
            for (int i = 0; i < 8; i++)
            {
                int[][] curS = s[i];
                String cur = sin[i];

                // Get binary values
                int row = Convert.ToInt32(cur[0] + "" + cur[5], 2);
                int col = Convert.ToInt32(cur.ToString().Substring(1, 5), 2);

                // Do S-Box table lookup
                outValput[i] = Convert.ToString(curS[row][col], 2);

                // Make sure the string is 4 bits
                while (outValput[i].Length < 4)
                    outValput[i] = "0" + outValput[i];

            }

            // Merge S-Box outValputs into one 32-bit string
            StringBuilder merged = new StringBuilder();
            for (int i = 0; i < 8; i++)
            {
                merged.Append(outValput[i]);
            }

            // Apply Permutation P
            StringBuilder mergedP = new StringBuilder();
            foreach (int j in p)
            {
                mergedP.Append(merged[j - 1]);
            }

            return mergedP.ToString();
        }
    }
}
