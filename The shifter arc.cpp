char shiftChar(char letter, int shift_value) {

	if (65 <= letter && letter <= 90) {

		if (shift_value > 25) {
			char newletter = ((letter + (shift_value % 26) + 26 - 'A') % 26 + 'A');
			return(newletter);

		}

		else if (shift_value < -25) {
			char newletter = ((letter + (shift_value % 26) + 26 - 'A') % 26 + 'A');
			return(newletter);

		}

		else {
			char newletter = ((letter + shift_value - 'A' + 26) % 26 + 'A');
			return(newletter);

		}
	}

	else if (97 <= letter && letter <= 122) {

		if (shift_value > 25) {
			char newletter = ((letter + (shift_value % 26) + 26 - 'a') % 26 + 'a');
			return(newletter);

		}

		else if (shift_value < -25) {
			char newletter = ((letter + (shift_value % 26) + 26 - 'a') % 26 + 'a');
			return(newletter);

		}

		else {
			char newletter = ((letter + shift_value - 'a' + 26) % 26 + 'a');
			return(newletter);

		}

	}

	else {
		return(letter);

	}
}
