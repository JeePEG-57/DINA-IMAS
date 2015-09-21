function [varargout] = ViewIDSDataAccess(varargin)

    persistent IDSData
  
    if nargin == 1
        if ischar(varargin{1})
            if strcmp(varargin{1},'Lock')
                mlock
                %disp('IDSData are locked');
            elseif strcmp(varargin{1},'Unlock')
                munlock
                %disp('IDSData are unlocked');
            end
        else 
            IDSData = varargin{1};
            %disp('IDSData set');
        end
    end

    
    if nargout == 1
        varargout{1} = IDSData;
        %disp('IDSData get');
    end

end