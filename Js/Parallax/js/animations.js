init = function(){
      jarallax = new Jarallax();
      
      jarallax.addAnimation('.planet2',[{progress: "0%", top:"70%"}, {progress: "100%", top: "40%"}]);
      jarallax.addAnimation('.planet1',[{progress: "0%", top:"90%"}, {progress: "100%", top: "-5%"}]);
      jarallax.addAnimation('.behind',[{progress: "0%", top:"0%"}, {progress: "100%", top: "-10%"}]);
	  }