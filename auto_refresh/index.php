<?php
include('db.php');
?>
<!DOCTYPE html>
<html lang="en">
   <head>
      <meta charset="utf-8">
      <meta name="robots" content="noindex, nofollow">
      <title>Comments</title>
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <link href="//maxcdn.bootstrapcdn.com/bootstrap/3.3.0/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
      <style type="text/css">
         hr{
         border-top: 1px solid #000 !important;
         }
         .row{
         margin-right: 0px;
         margin-left: 0px;
         }
         .comment{
         margin-right: 20px;
         margin-left: 20px; 
         margin-bottom: 30px;
         }
         .head{
         margin-bottom: 10px;
         }
         .user{
         margin-right: 10px;
         }    
      </style>
      <script src="//code.jquery.com/jquery-1.11.1.min.js"></script>
      <script src="//maxcdn.bootstrapcdn.com/bootstrap/3.3.0/js/bootstrap.min.js"></script>
   </head>
   <body>
      <div class="container">
         <div class="row">
            <h2>
               Comments <div class="pull-right"></div>
            </h2>
         </div>
         <hr>
         <div id="comments">
		 </div>
		 <hr/>
		 <div class="row" id="load_btn">
            <a href="javascript:void(0)" class="btn btn-primary" onclick="load_comments()">Load</a>
         </div>
      </div>
	  <script>
	  var click_count=0;
	  function load_comments(){
		  //jQuery('#comments').html("<img src='loader.gif'/>");
		  click_count=click_count+2;
		  /*jQuery('#comments').load('load_comment.php',{
			  click_count:click_count
		  });*/
		  jQuery.ajax({
			  url:'load_comment.php',
			  data:'click_count='+click_count,
			  type:'post',
			  success:function(result){
				  result=jQuery.parseJSON(result);
				  if(result.status=='no'){
					  jQuery('#load_btn').remove();
				  }
				  jQuery('#comments').append(result.html);
			  }
		  });
	  }
	  load_comments();
	  </script>
   </body>
</html>