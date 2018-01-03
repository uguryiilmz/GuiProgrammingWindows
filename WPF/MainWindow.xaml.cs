using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace UgurYilmazWPF
{
    /// <summary>
    public partial class MainWindow : Window
    {


      
        public MainWindow()
        {
            InitializeComponent();

            //string[] lines = { "line1", "line2" };

            //DataGridTextColumn col1 = new DataGridTextColumn();
            //dataGrid.Columns.Add(col1);
            //col1.Binding = new Binding(".");

            // dataGrid.Items.Add(lines[0]);
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            List<User> users = new List<User>();
            int counter = 0;
            string line;

            // Read the file and display it line by line.

            try
            {
                System.IO.StreamReader file = new System.IO.StreamReader(@"C:\temp\oscourse\360-p6.txt");
                


                while ((line = file.ReadLine()) != null)
                {
                    //Console.WriteLine(line); 
                    string[] other_part = line. Split('"');
                    string[] part = other_part[2].Split(',');
                    Console.Write(part[0]);
                    int number1 = Int32.Parse(part[1]);
                    int number2 = Int32.Parse(part[2]);
                    int number3 = Int32.Parse(part[3]);
                    users.Add(new User() { Name = other_part[1], First = number1, Second= number2, Third = number3 });
                    counter++;
                }

                file.Close();

                // Suspend the screen.
                Console.ReadLine();


            }
            catch (IOException ioex) {            
                throw new IOException("An error occurred while processing the file.", ioex);
            }
            /*catch (Exception ex)
            {
                throw new Exception("An generic error ocurred.");
            }*/

            dataGrid.ItemsSource = users;
        }


        public class User
        {
            public string Name { get; set; }

            public int First { get; set; }

            public int Second { get; set; }

            public int Third { get; set; }





        }
    }
}
