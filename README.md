Banking System
A comprehensive system designed to manage fundamental banking functionalities. This project supports three main user types: Clients, Bank Employees, and External Company Employees, each with a unique set of operations and commands.

Table of Contents

•Features

•User Types and Commands

   •Client
   
   •Bank Employee
   
   •Third Party Employee
   
•Common Commands
System Requirements
Features
Account Management: Open, close, and manage multiple bank accounts.
Check Redemption: Redeem checks with a secure verification process.
Inter-bank Transfers: Transfer accounts between different banks.
Task Management for Employees: Efficiently handle client requests and manage workload.
Persistent Data Storage: Save and reload data to ensure continuity.
User Types and Commands
Client
Clients can hold multiple accounts in different banks and perform various operations:

check_avl [bank_name] [account_number]
Displays the balance of the specified account.
open [bank_name]
Sends a request to open a new account in the specified bank.
close [bank_name] [account_number]
Sends a request to close the specified account.
redeem [bank_name] [account_number] [verification_code]
Redeems a check and transfers the amount to the specified account.
change [new_bank_name] [current_bank_name] [account_number]
Requests to transfer the specified account to another bank.
list [bank_name]
Lists all accounts the client holds in the specified bank.
messages
Displays all messages in chronological order.
Bank Employee
Bank Employees handle tasks generated by the bank based on client requests:

tasks
Shows the tasks assigned to the employee.
view [task_id]
Displays details of the specified task.
approve [task_id]
Approves and completes the task.
disapprove [task_id] [message]
Rejects and completes the task, sending a message to the client.
validate [task_id]
Validates client data for inter-bank transfers.
External Company Employee
External Company Employees are responsible for issuing checks to bank clients:

send_check [sum] [verification_code] [egn]
Issues a check to the client with the specified EGN.
Common Commands
All users can use the following commands:

exit
Logs out of the profile.
whoami
Displays complete information about the current user.
help
Shows the help menu with supported commands.
System Requirements
The system must support the following functionalities:

login
Authenticates a user into the system.
signup
Registers a new user in the system, allowing registration as any of the three user types.
create_bank
Creates a new bank in the system. No account is needed to create a bank, but the bank must exist to create a bank employee.
The system should maintain state persistence, saving data upon shutdown and reloading it upon restart. Proper file handling should be used for storing and retrieving data.

