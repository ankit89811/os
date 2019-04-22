semaphore ok_to_cross = 1; 
 

void enter_bridge() 
{  
P(ok_to_cross); 
}

void exit_bridge() 
{  
V(ok_ to_cross); 
} 


/the correct-direction enter function must be called before getting on the bridge.  The corresponding exit function must be called when the thread is ready to leave the bridge./

monitor bridge
{
  int num_waiting_north = 0;
  int num_waiting_south = 0;
  int on_bridge = 0;
  condition ok_to_cross; 
 int prev = 0; 
   void enter_bridge_north() 
{
   num_waiting_north++;  
 while (on_bridge ||(prev == 0 && num_waiting_south > 0))    ok_to_cross.wait();
   on_bridge=1;
   num_waiting_north--;  
 prev = 0; 
 } 
 
 
 void exit_bridge_north()
 {
   on_bridge = 0;  
 ok_to_cross.broadcast();  
}
 
 
 void enter_bridge_south() 
{
   num_waiting_south++;
 
  while (on_bridge ||(prev == 1 && num_waiting_north > 0))    ok_to_cross.wait();  
 on_bridge=1; 
  num_waiting_south--;  
 prev = 1;
  } 
 

   void exit_bridge_south() 
{   
on_bridge = 0; 
  ok_to_cross.broadcast();
  }  
 }