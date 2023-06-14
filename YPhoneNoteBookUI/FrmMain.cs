namespace YPhoneNoteBookUI
{
    using System;
    using System.Collections.Generic;
    using System.Windows.Forms;
    using YPhoneNoteBookCoreLibW;
    public partial class FrmMain : Form
    {
        public FrmMain()
        {
            InitializeComponent();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            New();
        }

        private void New()
        {
            FrmPersonMGR fPMGR = new FrmPersonMGR();
            fPMGR.ShowDialog();

            if (fPMGR.Success)
            {
                toolStripButton4.PerformClick();
            }
        }

        private void UpdateP()
        {

        }

        private void Delete()
        {

        }


        private void Dispaly(List<PersonW> ar)
        {
            List<ListViewItem> l = new List<ListViewItem>();

            foreach(PersonW s in ar)
            {
                ListViewItem lvi = new ListViewItem(s.Number.ToString());
                lvi.SubItems.Add(s.Name);
                lvi.SubItems.Add(s.Phone);
                l.Add(lvi);
            }

            listView1.Items.AddRange(l.ToArray());
            toolStripStatusLabel2.Text = l.Count.ToString();


        }
        private void Search()
        {
            if (string.IsNullOrEmpty(toolStripTextBox1.Text))
            {
                toolStripTextBox1.Focus();return;
            }

            Clear();

            List<PersonW> ar;
            if( new CPersonControllerW(Constants.ConnectionString).Search(toolStripTextBox1.Text.Trim(),out ar))
            {
                Dispaly(ar);
            }
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            Search();
        }

        private void FrmMain_Shown(object sender, EventArgs e)
        {
            toolStripTextBox1.Focus();
        }

        private void Clear()
        {
            listView1.Items.Clear();
            toolStripStatusLabel2.Text = "0";
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FrmAboutBox fA = new FrmAboutBox();
            fA.ShowDialog();
        }
    }
}
