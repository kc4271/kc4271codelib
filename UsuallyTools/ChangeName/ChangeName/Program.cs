using System;
using System.Text;
using System.IO;

namespace ChangeName
{
    class Program
    {
        static void Change(string dir,string str1,string str2,bool b_recursion)
        {
            DirectoryInfo di = new DirectoryInfo(dir);
            if (di.Exists)
            {
                if (b_recursion)
                {
                    DirectoryInfo[] dis = di.GetDirectories();
                    for (int i = 0; i < dis.Length; i++)
                    {
                        Change(dis[i].FullName, str1, str2, b_recursion);
                    }
                }
                FileInfo[] fis = di.GetFiles();
                for (int i = 0; i < fis.Length; i++)
                {
                    string name = fis[i].FullName;
                    string to = name.Replace(str1, str2);
                    if(name != to)
                        fis[i].MoveTo(to);
                }
            }
            else
            {
                Console.WriteLine("Cann't open directory {0}!", dir);
            }
        }

        static void Main(string[] args)
        {
            bool b_recursion = false;
            if (args.Length < 3)
            {
                Console.WriteLine("USEAGE: exe_file directory string_in_filename_1 string_in_filename_2 [/S]");
                Console.WriteLine("EXAMPLE: exe_file . \"_0_\" \"_1_\"");
                Console.WriteLine("File 0_0_1111.wav => 0_1_1111.wav");
                return;
            }

            if (args.Length >= 4)
            {
                if (args[3] == "/S" || args[3] == "/s")
                {
                    b_recursion = true;
                }
            }
         
            Change(args[0], args[1], args[2], b_recursion);
        }
    }
}
