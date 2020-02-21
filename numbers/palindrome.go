package main

import "fmt"

func isPalindrome(in string) (bool) {
   for i := 0; i < len(in)/2; i++ {
      if in[i] != in[len(in)-i-1] {
         return false
      } 
   }    
   return true
}

func main() {     
   var a string = "02/02/2020"
   var b string = "02022020"
   fmt.Println("isPalindrome:String")
   fmt.Println(isPalindrome(a), a)
   fmt.Println(isPalindrome(b), b)
}
