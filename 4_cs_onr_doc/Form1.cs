using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
//using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace onrDoc
{

    public class Func
    {
        public string description;
        public string defination;
        public Func()
        {
            description = "";
            defination = "";
        }
    }
 
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();

        }

        void save_function(StreamWriter writer,string descStr,string funcStr)
        {

            //MessageBox.Show("a");
            descStr = descStr.Replace("//", "\n");
            descStr = descStr.Replace("$", " ");
            funcStr = funcStr.Replace("//$", " ");
            funcStr = funcStr.Replace("{", " ");
            string[] split1 = funcStr.Split('(');
            string[] split2 = split1[1].Split(',');
            //string output = "";

 	        writer.Write("<div class =\"function\">"+
			split1[0] +
            "(<div class=\"argument\">");
            for (int i = 0; i < split2.Length; i++)
            {
                split2[i] = split2[i].Replace("}", " ");
                split2[i] = split2[i].Replace(")", " ");
                //output += split2[i];

                //MessageBox.Show(split2[i]);
                writer.Write(split2[i]);
                if(i!=split2.Length-1)
                    writer.Write(",");
                writer.Write("<br>\n");
            }

            writer.Write("</div>)"+
            "<div class=\"description\">"+descStr+"</div>\n"+
			"<br>\n\n</div>\n<br>\n");
        }

 
        private void btnSave_Click ( object sender , EventArgs e )
        {
            string openFileName =  tbOpenFileName.Text;
            string outputFileName = tbOutputFileName.Text;
            if (!File.Exists(openFileName))
            {
                MessageBox.Show(openFileName + " adında cs dosyası yok!");
                return;
            }

            // Read every line in the file.
            StreamReader reader = new StreamReader(openFileName);
            StreamWriter writer = new StreamWriter(outputFileName);
            writer.WriteLine("<!doctype html>\n<html>\n<head>\n<title> OnurDoc </title>"+
            "<link rel=\"stylesheet\" type=\"text/css\" href=\"document.css\">\n" +
            "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"/>\n</head>\n<body>");

            writer.WriteLine("<div class=\"header\">"
                   +"-------------"+ openFileName +"------------"+
               " </div>");
            string line="";

           // string readedStr = "";
            bool recording = false;
            bool functioning = false;
            List<Func> functions = new List<Func>();
            int counter = 0;
            while ((line = reader.ReadLine())!=null)
            {
                //string[] tokens = line.Split(new[] { "//" }, StringSplitOptions.None);

                if (line.IndexOf("//$") != -1)
                {
                    //MessageBox.Show("b");
                    if (recording==false)
                    {

                        functions.Add(new Func());
                        recording = true;
                        functioning = false;
                    }
                    else 
                    {

                        recording = false;
                        functioning = true;

                    }

                }
                if (recording)
                {
                    //readedStr += line;
                    functions[functions.Count-1].description += line+"<br>";
                }else if (functioning)  
                {

                    if (line.IndexOf("(") != -1)
                        functions[functions.Count - 1].defination += "Line "+(counter+1).ToString()+": ";

                       functions[functions.Count-1].defination += line;

                    if (line.IndexOf(")")!=-1)
                        functioning = false;

                }
                counter++;
            }
            for (int i = 0; i < functions.Count; i++)
            {
                save_function(writer, functions[i].description, functions[i].defination);
            }

            writer.Write("</body>");
            reader.Close(); 

            writer.Close();
            MessageBox.Show("Kaydetme Başarılı");


        }
    }
}
