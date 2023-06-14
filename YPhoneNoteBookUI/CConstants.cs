using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YPhoneNoteBookUI
{
    class Constants
    {
        private static string dbPath = System.IO.Directory.GetCurrentDirectory() + "\\DataBase\\db.accdb";

        private static string connectionString = "DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};pwd=123;User ID=admin;DBQ=" + dbPath;

        internal static string DbPath
        {
            get { return dbPath; }
        }

        internal static string ConnectionString
        {
            get { return connectionString; }
        }
    }
}
