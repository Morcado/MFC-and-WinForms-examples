using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Primero_CSharp{
    public partial class Form1 : Form{
        string cad;
        string cad2;
        public Form1(){
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e){
            textBox1.Text = "Hola";
            textBox2.Text = "Mundo";
            
        }

        private void Accion_Click(object sender, EventArgs e){
            cad = textBox1.Text;
            cad2 = textBox2.Text;
            textBox2.Text = cad;
            textBox1.Text = cad2;
        }

        private void textBox2_TextChanged(object sender, EventArgs e){

        }
    }
}
