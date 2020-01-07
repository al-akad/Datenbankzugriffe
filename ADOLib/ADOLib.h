#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::OleDb;
using namespace System::Windows::Forms;

namespace ADOLib 
{
	public ref class DBConnection
	{

	private:
		static OleDbConnection^ dbConn;
		static String^ connectionString;

	public:

		
		
		/// <summary>
		/// Stellt eine Verbindung zu einer Datenbank her.
		/// </summary>
		/// <param name="connectionString">Datenbankspezifische Verbindungszeichenfolge</param>
		/// <returns></returns>
		static bool ConnectToDatabase(String^ connectionString)
		{

			bool retValue = false;

			try
			{
				dbConn = gcnew OleDbConnection(connectionString);
				dbConn->Open();

				DBConnection::connectionString = connectionString;

				retValue = true;

			}
			catch (Exception ^ ex)
			{
				MessageBox::Show(ex->Message, "Datenbankverbindung", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			return retValue;

		}


		static void CloseConnection()
		{

			if (dbConn != nullptr && dbConn->State == ConnectionState::Open)
				dbConn->Close();


		}

		//// Getter-Methode
		//static OleDbConnection^ GetDBCOnnection()
		//{
		//	return dbConn;
		//}

		//// Setter-Methode
		//static void SetDBConnection(OleDbConnection^ dbConn)
		//{
		//	DBConnection::dbConn = dbConn;
		//}

		static property OleDbConnection^ DBConn
		{
			OleDbConnection^ get()
			{
				return dbConn;
			}

			//void set(OleDbConnection^ dbConn)
			//{
			//	DBConnection::dbConn = dbConn;
			//}
		}

		static Object^ ExecuteScalar(String ^ SQL)
		{

			Object^ retValue = System::DBNull::Value;

			if (dbConn == nullptr || dbConn->State != ConnectionState::Open)
				return retValue;

			try
			{
				OleDbCommand^ cmd = gcnew OleDbCommand(SQL, dbConn);
				retValue = cmd->ExecuteScalar();

			}
			catch (Exception ^ ex)
			{
				MessageBox::Show(ex->Message, "ExecuteScalar", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			return retValue;

		}


		static int ExecuteNonQuery(String^ SQL)
		{
			int retValue = 0;

			if (dbConn == nullptr || dbConn->State != ConnectionState::Open)
				return retValue;


			try
			{
				OleDbCommand^ cmd = gcnew OleDbCommand(SQL, dbConn);
				retValue = cmd->ExecuteNonQuery();

			}
			catch (Exception ^ ex)
			{
				MessageBox::Show(ex->Message, "ExecuteNonQuery", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			return retValue;

		}

		static String^ Quote(String^ value)
		{
			return "'" + value->Replace("'", "''") + "'";
		}



		
	};
}
