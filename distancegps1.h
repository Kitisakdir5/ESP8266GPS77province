
double DeltaPhi , DeltaLamda ;
double RadiusE = 6378100 ;  /// Radius in m
double Phi1inr,Phi2inr,Lamda1inr,Lamda2inr ,pi22 ,pi7,p180 ;
double DeltaPhid2 , DeltaPhim2 , xs3 , ys3 ,xys3 ;


//  function solution distance 
double soldistance1(double Phi1 , double Lamda1 , double Phi2, double Lamda2) {

/////////////////////  solution 1  ////////////////////////
  /////////// φ1 = lat1* Pi/180 , φ2 = lat2* Pi/180 //////////////
 //  Phi1 = gpslat ;
 //  Phi2 = LatitudeC1 ;
   pi22 = 22 ;
   pi7 =  7;
   p180 = 180 ;
   Phi1inr = Phi1 * (pi22/pi7) / p180 ;  /// 32.91410
   Phi2inr = Phi2 * (pi22/pi7) / p180 ;
 ////////////  Δφ = (lat2-lat1) * Pi/180 =   ////////////////////
   DeltaPhi = (Phi2 - Phi1)* (pi22/pi7) / p180 ;
   DeltaPhid2 = DeltaPhi/2 ; 
   DeltaPhim2 = ((Phi2 + Phi1)* (pi22/pi7) / p180)/2 ; // add *(pi22/pi7)/180 again
   
/////////// λ1 = long1* Pi/180 , λ2 = long2* Pi/180 //////////////
 //  Lamda1 = gpslong ;
 //  Lamda2 = LongitudeC1  ;
   Lamda1inr = Lamda1 * (pi22/pi7) / p180;
   Lamda2inr = Lamda2 * (pi22/pi7) / p180 ;
      
 ////////////  Δλ = (long2-long1) * Pi/180 =   ////////////////////
   DeltaLamda = (Lamda2 - Lamda1)* (pi22/pi7) / p180 ; // add *(pi22/pi7)/180 again
   /////////// 

////////////////////////////////// solution 3 /////////////////////
/// The solution 3 is right.
 /// x =  Δλ * cos (Δφ )
 /// y = Δφ 
 //  d = R * sqrt(,x^2+y^2) 
  xs3 = DeltaLamda * cos(DeltaPhim2) ;
  ys3 = DeltaPhi ;
  xys3 = (xs3*xs3) + (ys3 *ys3) ;
 double distancef = RadiusE  * sqrt(xys3) ;
 

//////////////////////////////////////////////////////////
   //////// clear data  ///////////////
   Phi1 = 0 ;
   Phi2 = 0 ;
   Lamda1 = 0 ;
   Lamda2 = 0 ;
   Phi1inr = 0 ;
   Phi2inr = 0 ;
   Lamda1inr = 0 ;
   Lamda2inr = 0 ;
   DeltaLamda = 0 ;
   DeltaPhi  = 0 ;
   DeltaPhim2 = 0 ;
   xs3 = 0 ;
   ys3 = 0 ;

  return distancef ;
}



