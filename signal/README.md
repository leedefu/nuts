----------------  
### Send a signal command: kill -s SIGNUM pid
----------------  
* SIGINT: 
  You can also type Control-C to send SIGINT signal
----------------  
* SIGABRT:   
  When a process is sent SIGABRT, by defalut process will be terminiated.  
  SIGABRT can be sent by calling abort() function in same process or by kill command (eg. kill -s SIGABRT <pid>) from other process.
----------------  
