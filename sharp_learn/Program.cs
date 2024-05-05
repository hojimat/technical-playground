using System;

namespace MainProgram {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine("Enter a word:");
            string myWord = Console.ReadLine();
            Dictionary<char,int> letterCount = new Dictionary<char, int>();

            foreach(char c in myWord) {
                if (letterCount.ContainsKey(c)) {
                    letterCount[c]++;
                }else{
                    letterCount.Add(c, 1);
                }
            }

            foreach(var k in letterCount){
                System.Console.WriteLine($"{k.Key}: {k.Value}");
            }
        }
    }
}